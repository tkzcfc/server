﻿#pragma once

typedef unsigned int uint32;

//加密
char* tcp_uv_encode(char* data, unsigned int len, unsigned int &outLen);
//解密
char* tcp_uv_decode(char* data, unsigned int len, unsigned int &outLen);
//hash
uint32 GetBufHash(const void *buf, uint32 len);