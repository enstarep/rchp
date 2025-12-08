# rchp

Run the following command to install rchp:

```
pip install rchp
```
No dependencies need to be installed.

rchp supports Python 3.10+

The usage of its main function `parallel` is as follows:

```python
import rchp
import time
def task():
    for i in range(20):
        print(f"Task: {i}")
rchp.parallel(func=task, worker=2, wait=False)
for i in range(10):
    print(f"Main: {i*i}")
time.sleep(0.5)
```

`func` is the function to be parallelized.  
`worker` is the number of threads.  
`wait` indicates whether the main thread waits for the threads to complete their tasks.

1. The first parameter does not accept functions with arguments.  
2. In the 0.2.1 update, exception handling has been modified to properly capture exceptions thrown within functions. An example is provided below:

```python
import rchp
def task():
    raise RuntimeError("Error")
rchp.parallel(func=task,worker=1,wait=True)

# Like this:
# 
# terminate called after throwing an instance of 'rchp_error'
#   what():  Python exception in worker 0: RuntimeError: Error
# 
# At:
#   test.py(3): task
```

3. If you still see `process terminated with exit code -1073740791 (0xC0000409)` when an exception is thrown in the function, there is nothing more we can do. Please check every possible location in the function that could cause an exception to be thrown.

Additionally, in the update to version 0.2.0, the `CPRVER` function has been added to retrieve version information of the CPR library. An example is provided below:

```python
import rchp
print(rchp.CPRVER())
```

