# ThreadPool


```
int initThreadCount = 1;    // 初始线程个数
int maxThreadCount = 4;     // 最大线程个数
int idleSec = 6;            // 当某个线程空闲6秒时，将退出
threadpool::ThreadPool pool(initThreadCount, maxThreadCount, idleSec);

// 向线程池中添加任务
pool.AddTask([](){
  printf("this is task1.\n");
});

pool.AddTask([](){
  printf("this is task2.\n");
});

pool.AddTask([](){
  printf("this is task3.\n");
});
```
