/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef _THRIFT_CONCURRENCY_FUNCTION_RUNNER_H
#define _THRIFT_CONCURRENCY_FUNCTION_RUNNER_H 1

#include <tr1/functional>
#include "thrift/lib/cpp/concurrency/Thread.h"

namespace apache { namespace thrift { namespace concurrency {

/**
 * Convenient implementation of Runnable that will execute arbitrary callbacks.
 * Interfaces are provided to accept both a generic 'void(void)' callback, and
 * a 'void* (void*)' pthread_create-style callback.
 *
 * Example use:
 *  void* my_thread_main(void* arg);
 *  shared_ptr<ThreadFactory> factory = ...;
 *  shared_ptr<Thread> thread =
 *    factory->newThread(shared_ptr<FunctionRunner>(
 *      new FunctionRunner(my_thread_main, some_argument)));
 *  thread->start();
 *
 *
 */

class FunctionRunner : public Runnable {
 public:
  // This is the type of callback 'pthread_create()' expects.
  typedef void* (*PthreadFuncPtr)(void *arg);
  // This a fully-generic void(void) callback for custom bindings.
  typedef std::tr1::function<void()> VoidFunc;

  /**
   * Given a 'pthread_create' style callback, this FunctionRunner will
   * execute the given callback.  Note that the 'void*' return value is ignored.
   */
  FunctionRunner(PthreadFuncPtr func, void* arg)
   : func_(std::tr1::bind(func, arg))
  { }

  /**
   * Given a generic callback, this FunctionRunner will execute it.
   */
  FunctionRunner(const VoidFunc& cob)
   : func_(cob)
  { }


  void run() {
    func_();
  }

 private:
  VoidFunc func_;
};

}}} // apache::thrift::concurrency

#endif // #ifndef _THRIFT_CONCURRENCY_FUNCTION_RUNNER_H
