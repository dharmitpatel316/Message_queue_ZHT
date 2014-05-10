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
 * cpp_zhtclient_test.cpp
 *
 *  Created on: Aug 7, 2012
 *      Author: Xiaobingo
 *      Contributor: Tony, KWang, DZhao
 */

#include "cpp_zhtclient.h"
#include "uuid.h"

#include  <getopt.h>
#include  <stdlib.h>
#include   <stdio.h>
#include   <string>
#include   <exception>
#include <iostream>
#include <ctime>
#include <time.h>
#include <fstream>
#include <pthread.h>
#include <boost/lexical_cast.hpp>

using namespace std;

void test_insert();
void test_lookup();
void test_remove();
void test_append();

void runtest();
string create_uuid();
void dharmit_insert();
void dharmit_lookup();
void dharmit_remove();
void dharmit_append();
void dharmit_create_queue();
void push();
void pop();
void delete_queue();
void fetch_node();
void *threadedTest(void *threadid);

void runn();
void printUsage(char *argv_0);

ZHTClient zc;
long numofmessages;
long numofmessagesperthread;

void test_all() {

	printf("starting test_insert...\n");
	test_insert();

	printf("starting test_lookup...\n");
	test_lookup();

	printf("starting test_remove...\n");
	test_remove();

	printf("starting test_append...\n");
	test_append();
}

void test_lookup_shared(string key) {

	string result;
	int rc = zc.lookup(key, result);

	if (rc == 0)
		printf("LOOKUP OK, rc(%d), value={%s}\n", rc, result.c_str());
	else
		printf("LOOKUP ERR, rc(%d), value={%s}\n", rc, result.c_str());
}
void push(){
	string uuid=create_uuid();
	cout<<uuid<<endl;
	string val,queuename,result;
	printf("Enter the message=");
	cin>>val;
	printf("Enter queue name=");
	cin>>queuename;
	int rc = zc.push(uuid, val,queuename,result);

	if (rc == 0)
		printf("PUSH OK, rc(%d)\n", rc);
	else
		printf("PUSH ERR, rc(%d)\n", rc);

// based on the result.c_str() check the value and make fetch_node or update_node call.
	


/*	if (rc == 0)
		printf("LOOKUP OK, rc(%d), value={%s}\n", rc, 	result.c_str());
	else
		printf("LOOKUP ERR, rc(%d), value={%s}\n", rc, result.c_str());
*/
}
void pop(){
	string uuid=create_uuid();
	cout<<uuid<<endl;
	string queuename,result;
	printf("Enter queue name=");
	cin>>queuename;
	
	int rc=zc.pop(uuid,queuename,result);
	printf("rc cpp_zhtclient_test value=%d\n",rc);
	if (rc == 0)
		printf("POP OK, rc(%d), value={%s}\n", rc, 	result.c_str());
	else
		printf("POP ERR, rc(%d), value={%s}\n", rc, result.c_str());

}
void delete_queue(){
}
void fetch_node(){
}


void *threadedTest(void *threadid){

long tid;
tid = (long)threadid;
   printf("Sending of Message Started #%ld!\n", tid);
   

	string msg="dharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmitdharmit";
string queuename="q1",result;

	ofstream myfile;
/*
std::stringstream mystream;
mystream << tid;
*/

string sen="sending"+boost::lexical_cast<std::string>(tid)+".csv";
string rec="receiving"+boost::lexical_cast<std::string>(tid)+".csv";

int countpush=0,countpop=0;
clock_t start;
//clock_t start=clock();
myfile.open(sen.c_str(), ios::out | ios::app);
for(int i=0;i<numofmessagesperthread;i++){

start=clock();
string uuid=create_uuid();
int rc = zc.push(uuid, msg,queuename,result);
if(rc==0)
countpush++;
myfile<<i<<","<<((float)(clock()-start))/CLOCKS_PER_SEC<<"\n";
}

myfile.close();

myfile.open(rec.c_str(), ios::out | ios::app);
int tots=0;
int t=0;
for(int i=0;;i++,tots++){
start=clock();
string uuid=create_uuid();
int rc=zc.pop(uuid,queuename,result);
if(rc==0){
	countpop++;
	myfile<<countpop<<","<<((float)(clock()-start))/CLOCKS_PER_SEC<<"\n";
}
if(countpop==numofmessagesperthread){
	//t++;
	break;
}
//if(t==5)break;
}
myfile.close();
cout<<"Time Difference: "<<clock() - start<<endl;
cout<<"PUSH OPERATION ="<<countpush<<"/"<<numofmessagesperthread<<endl;
cout<<"POP OPERATION ="<<tots+1<<"/"<<countpop<<endl;




	pthread_exit(NULL);

}
void runtest(){

int n,numofthreads;
cout<<"Enter the number of messages=";
cin>>numofmessages;
cout<<"Enter the number of threads=";
cin>>numofthreads;

numofmessagesperthread=numofmessages/numofthreads;


pthread_t thread[numofthreads];
   pthread_attr_t attr;
   int rc;
   long t;
   void *status;

   /* Initialize and set thread detached attribute */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

for(t=0; t<numofthreads; t++) {
      printf("Main: creating thread %ld\n", t);
      rc = pthread_create(&thread[t], &attr, threadedTest, (void *)t); 
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
         }
      }

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
   for(t=0; t<numofthreads; t++) {
      rc = pthread_join(thread[t], &status);
      if (rc) {
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
         }
      printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
      }
 

}
void test_all_other() {

	string key = "hello";
	string val = "1.zht";

	zc.insert(key, val);
	test_lookup_shared(key);

	val = "2.zht";
	zc.append(key, val);
	test_lookup_shared(key);

	val = "3.zht";
	zc.insert(key, val);
	test_lookup_shared(key);

	val = "4.zht";
	zc.append(key, val);
	test_lookup_shared(key);
}

void runn(){

	int n=0;;
	while(n!=5){	
	printf("\n1. Insert\n");
	printf("2. Lookup\n");
	printf("3. Remove\n");
	printf("4. Append\n");
	printf("5. exit\n");
	printf("6. Create Queue\n");
	printf("7. Create UUID\n");
	printf("8. Push\n");
	printf("9.Pop \n");
	printf("10. Test \n");
	printf("Enter the option to select=");
	scanf("%d",&n);
	
	

		switch(n){
			case 1:
			
			dharmit_insert();

			break;
			case 2:
			dharmit_lookup();
			break;
			case 3:
			dharmit_remove();
			break;
			case 4:
			dharmit_append();
			break;
			case 5:
				exit;
			break;
			case 6:
			dharmit_create_queue();
			break;
			case 7:
			cout<<create_uuid();
			case 8:
			push();			
			break;
			case 9:
			pop();
			break;
			case 10:
			runtest();
			break;
			default:
				break;
		}

	}


}

int main(int argc, char **argv) {

	extern char *optarg;

	int printHelp = 0;
	string zhtConf = "";
	string neighborConf = "";

	int c;
	while ((c = getopt(argc, argv, "z:n:h")) != -1) {
		switch (c) {
		case 'z':
			zhtConf = string(optarg);
			break;
		case 'n':
			neighborConf = string(optarg);
			break;
		case 'h':
			printHelp = 1;
			break;
		default:
			fprintf(stderr, "Illegal argument \"%c\"\n", c);
			printUsage(argv[0]);
			exit(1);
		}
	}

	int helpPrinted = 0;
	if (printHelp) {
		printUsage(argv[0]);
		helpPrinted = 1;
	}

	try {

		if (!zhtConf.empty() && !neighborConf.empty()) {

			zc.init(zhtConf, neighborConf);

			//test_all_other();

			runn();
			//test_all();

			zc.teardown();

		} else {

			if (!helpPrinted)
				printUsage(argv[0]);
		}
	} catch (exception& e) {

		fprintf(stderr, "%s, exception caught:\n\t%s", "ZHTServer::main",
				e.what());
	}

}

void printUsage(char *argv_0) {

	fprintf(stdout, "Usage:\n%s %s\n", argv_0,
			"-z zht.conf -n neighbor.conf [-h(help)]");
}

string create_uuid(){
	Uuid* s=new Uuid();
	return s->generate_uuid(); 
}
void dharmit_insert(){
	string key;
	string val;
	printf("Enter the key=");
	cin>>key;
	printf("Enter the value=");
	cin>>val;
	int rc = zc.insert(key, val);

	if (rc == 0)
		printf("INSERT OK, rc(%d)\n", rc);
	else
		printf("INSERT ERR, rc(%d)\n", rc);
	
}
void dharmit_create_queue(){

	string key;
	string val;
	printf("Enter the key=");
	cin>>key;
	printf("Enter the value=");
	cin>>val;
	int rc = zc.create_queue(key, val);

	if (rc == 0)
		printf("INSERT OK, rc(%d)\n", rc);
	else
		printf("INSERT ERR, rc(%d)\n", rc);

}
void test_insert() {

	string key = "goodman";
	string val =
			"[1],The Only Thing Necessary for the Triumph of Evil is that Good Men Do Nothing";

	int rc = zc.insert(key, val);

	if (rc == 0)
		printf("INSERT OK, rc(%d)\n", rc);
	else
		printf("INSERT ERR, rc(%d)\n", rc);
}

void dharmit_lookup(){
	
	string key;
	printf("Enter the key=");
	cin>>key;
	string result;
	int rc = zc.lookup(key, result);

	if (rc == 0)
		printf("LOOKUP OK, rc(%d), value={%s}\n", rc, result.c_str());
	else
		printf("LOOKUP ERR, rc(%d), value={%s}\n", rc, result.c_str());
}


void test_lookup() {

	test_insert();

	string key = "goodman";

	string result;
	int rc = zc.lookup(key, result);

	if (rc == 0)
		printf("LOOKUP OK, rc(%d), value={%s}\n", rc, result.c_str());
	else
		printf("LOOKUP ERR, rc(%d), value={%s}\n", rc, result.c_str());
}
void dharmit_remove(){
	string key;
	printf("Enter the key");
	cin>>key;

	int rc = zc.remove(key);

	if (rc == 0)
		printf("REMOVE OK, rc(%d)\n", rc);
	else
		printf("REMOVE ERR, rc(%d)\n", rc);
}
void test_remove() {

	test_insert();

	string key = "goodman";

	int rc = zc.remove(key);

	if (rc == 0)
		printf("REMOVE OK, rc(%d)\n", rc);
	else
		printf("REMOVE ERR, rc(%d)\n", rc);
}

void dharmit_append(){
	string key;
	string val;
	printf("Enter the key=");
	cin>>key;
	printf("Enter the value");
	cin>>val;

	int rc = zc.append(key, val);

	if (rc == 0)
		printf("APPEND OK, rc(%d)\n", rc);
	else
		printf("APPEND ERR, rc(%d)\n", rc);

	string result;
	rc = zc.lookup(key, result);

	if (rc == 0)
		printf("LOOKUP OK, rc(%d), value={%s}\n", rc, result.c_str()); //todo: consider ": delimited"
	else
		printf("LOOKUP ERR, rc(%d), value={%s}\n", rc, result.c_str()); //todo: consider ": delimited"
}

void test_append() {

	test_insert();

	string key = "goodman";
	string val2 =
			"[2],The Only Thing Necessary for the Triumph of Evil is that Good Men Do Nothing";

	int rc = zc.append(key, val2);

	if (rc == 0)
		printf("APPEND OK, rc(%d)\n", rc);
	else
		printf("APPEND ERR, rc(%d)\n", rc);

	string result;
	rc = zc.lookup(key, result);

	if (rc == 0)
		printf("LOOKUP OK, rc(%d), value={%s}\n", rc, result.c_str()); //todo: consider ": delimited"
	else
		printf("LOOKUP ERR, rc(%d), value={%s}\n", rc, result.c_str()); //todo: consider ": delimited"
}
