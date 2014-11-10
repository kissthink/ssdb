/*
Copyright (c) 2012-2014 The SSDB Authors. All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file.
*/
#ifndef SSDB_TTL_H_
#define SSDB_TTL_H_

#include "include.h"
#include "ssdb.h"
#include "util/thread.h"
#include <string>

class ExpirationHandler
{
public:
	Mutex mutex;
	ExpirationHandler(SSDB *ssdb);
	~ExpirationHandler();
	int del_ttl(const Bytes &key);
	int set_ttl(const Bytes &key, int64_t ttl);
	int64_t get_ttl(const Bytes &key);

private:
	SSDB *ssdb;
	volatile bool thread_quit;
	std::string list_name;
	int64_t first_timeout;

	void start();
	void stop();
	static void* thread_func(void *arg);
	void load_expiration_keys_from_db(int num);
};

#endif
