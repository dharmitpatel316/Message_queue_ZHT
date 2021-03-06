/*
 * Copyright 2010-2020 DatasysLab@iit.edu(http://datasys.cs.iit.edu/index.html)
 *      Director: Ioan Raicu(iraicu@cs.iit.edu)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This file is part of ZHT library(http://datasys.cs.iit.edu/projects/ZHT/index.html).
 *      Tonglin Li(tli13@hawk.iit.edu) with nickname Tony,
 *      Xiaobing Zhou(xzhou40@hawk.iit.edu) with nickname Xiaobingo,
 *      Ke Wang(kwang22@hawk.iit.edu) with nickname KWang,
 *      Dongfang Zhao(dzhao8@@hawk.iit.edu) with nickname DZhao,
 *      Ioan Raicu(iraicu@cs.iit.edu).
 *
 * cpp_zhtclient.h
 *
 *  Created on: Sep 16, 2012
 *      Author: Xiaobingo
 *      Contributor: Tony, KWang, DZhao
 */

#ifndef ZHTCLIENT_H_
#define ZHTCLIENT_H_

#include <stdint.h>
#include <map>
#include <string>
using namespace std;

#include "lru_cache.h"

#include "ProxyStubFactory.h"

/*
 *
 */
class ZHTClient {

public:
	ZHTClient();

	ZHTClient(const string &zhtConf, const string &neighborConf);
	virtual ~ZHTClient();

	int init(const string &zhtConf, const string &neighborConf);
	int init(const char *zhtConf, const char *neighborConf);
	int lookup(const string &key, string &result);
	int lookup(const char *key, char *result);
	int remove(const string &key);
	int remove(const char *key);
	int insert(const string &key, const string &val);
	int insert(const char *key, const char *val);
	int append(const string &key, const string &val);
	int append(const char *key, const char *val);
	int compare_swap(const string &key, const string &seen_val,
			const string &new_val, string &result);
	int compare_swap(const char *key, const char *seen_val, const char *new_val,
			char *result);
	int state_change_callback(const string &key, const string &expected_val,
			int lease);
	int state_change_callback(const char *key, const char *expeded_val,
			int lease);
	int teardown();
	int create_queue(const string &key, const string &val);
	int create_queue(const char *key, const char *val);
	int push(const char *key, const char *val, const char *new_val, char *result);
    	int push(const string &key, const string &val, const string &new_val, string &result);
    
    	int pop(const char *key, const char *val, char *result);
    	int pop(const string &key, const string &val, string &result);
    
    	int delete_queue(const char *key, const char *val);
    	int delete_queue(const string &key, const string &val);
    
    	int fetch_node(const char *key, char *result);
    	int fetch_node(const string &key, string &result);
    	
	int add_node(const char *key, char *result);
    	int add_node(const string &key, string &result);
	void runtest();

private:
	int commonOp(const string &opcode, const string &key, const string &val,
			const string &val2, string &result, int lease);
	string commonOpInternal(const string &opcode, const string &key,
			const string &val, const string &val2, string &result, int lease);
	string extract_value(const string &returnStr);


private:
	ProtoProxy *_proxy;
	int _msg_maxsize;
	
};

#endif /* ZHTCLIENT_H_ */
