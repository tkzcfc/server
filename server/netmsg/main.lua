require "lfs"


local workRootPath = "netmsg"
--local outpbDir = ""


-----------------------------------------------------****-----------------------------------------------------



local pbDir = "pb"
os.execute("if exist pb (rd /s /q pb)")
lfs.mkdir(pbDir)

function check(p)
    if p == "" then
        return p
    end
    if p:sub(#p, #p + 1) ~= "/" then
        p = p.."/"
    end
    return p
end

workRootPath = check(workRootPath)
--outpbDir = check(outpbDir)
pbDir = check(pbDir)


--get filename  
function getFileName(str)  
    local idx = str:match(".+()%.%w+$")  
    if(idx) then  
        return str:sub(1, idx-1)  
    else  
        return str  
    end  
end  

--get file postfix  
local function getExtension(str)  
    return str:match(".+%.(%w+)$")  
end  

local curPath = lfs.currentdir().."/"
local fileList = {}
local fileDirList = {}
  
local function changeFile(rootpath)  
    for entry in lfs.dir(rootpath) do  
        if entry ~= '.' and entry ~= '..' then  
            local path = rootpath .. '/' .. entry  
            local attr = lfs.attributes(path)  
            if attr.mode ~= 'directory' then
                local postfix = getExtension(entry)
                if postfix == "proto" then

                    local cmd = "--descriptor_set_out "

                    --proto文件相对路径
                    local pf = string.sub(path, string.len(curPath) + 1, string.len(path))
                    pf = string.sub(pf, 2, string.len(pf))

                    local r = "proto"
                    local p = string.sub(pf, 1, #r)
                    if p == r then
                        p = string.sub(pf, #r + 2, #pf + 1)
                    end
                    local t = getFileName(entry)..".pb"
                    p = string.gsub(p, entry, t)

                    local d = string.gsub(p, t, "")
                    
                    if d ~= "" then
                        d = pbDir..d
                        if not fileDirList[d] then
                            if not lfs.mkdir(d) then
                                print("create directory "..d.." fail")
                                os.execute("pause")
                                os.exit(0)
                            end
                        else
                            fileDirList[d] = true
                            -- print("create", d)
                        end
                    end

                    print(pf, "->", pbDir .. p)

                    cmd = cmd .. pbDir .. p .." "
                    cmd = cmd .. pf
                    cmd = "protoc.exe " .. cmd
                    -- print(cmd)
                    local r = os.execute(cmd)
                    if r ~= 0 then
                       print("fail")
                       os.execute("pause")
                       os.exit(0)
                    end

                    table.insert(fileList, p)
                end
            else  
                changeFile(path)  
            end  
        end  
    end  
end  

changeFile(curPath)

function writefile(path, content, mode)
    mode = mode or "wb+"
    local file = io.open(path, mode)
    if file then
        if file:write(content) == nil then return false end
        io.close(file)
        return true
    end
    return false
end

local script = "local M = {}\n"
for i = 1, #fileList do
    script = script .. string.format("M[%d] = \"%s\"\n", i, workRootPath..pbDir..tostring(fileList[i]))
end
script = script .. "return M"

if writefile(pbDir.."msglist.lua", script, "wb") then
    print("finish")
else
    print("write error")
end

-----------------------------------------------------****-----------------------------------------------------
