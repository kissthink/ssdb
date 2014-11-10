/*
Copyright (c) 2012-2014 The SSDB Authors. All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file.
*/
#ifndef SSDB_PROC_H_
#define SSDB_PROC_H_

class Bytes;
struct Command;

class ProcMap
{
public:
	ProcMap();
	~ProcMap();
	Command* find(const Bytes &str);
};

#endif
