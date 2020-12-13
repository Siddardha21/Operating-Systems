# Operating System (CS312) Assignments 

<br/>

<img align="left" alt="C" width="30px" src="https://raw.githubusercontent.com/github/explore/80688e429a7d4ef2fca1e82350fe8e3517d3494d/topics/c/c.png" />
<img align="left" alt="C++" width="30px" src="https://raw.githubusercontent.com/github/explore/80688e429a7d4ef2fca1e82350fe8e3517d3494d/topics/cpp/cpp.png" />
<img align="left" alt="Python" width="30px" src="https://raw.githubusercontent.com/github/explore/80688e429a7d4ef2fca1e82350fe8e3517d3494d/topics/python/python.png" />
<img align="left" alt="Java" width="30px" src="https://raw.githubusercontent.com/github/explore/80688e429a7d4ef2fca1e82350fe8e3517d3494d/topics/java/java.png"/>
<img align="left" alt="Terminal" width="30px" src="https://raw.githubusercontent.com/github/explore/80688e429a7d4ef2fca1e82350fe8e3517d3494d/topics/terminal/terminal.png"/>
<img align="left" alt="Terminal" width="30px" src="https://raw.githubusercontent.com/github/explore/80688e429a7d4ef2fca1e82350fe8e3517d3494d/topics/linux/linux.png" />

<br/>


### **Assignment-1**: Update the code for the server and client program.
1. The sever should look for the file requested by the client in the current working directory. If the file is available, then it should read the file and send the contents of the files to the client. The client should receive the file contents and display it.
2. After displaying all the contents of the file, the client should close.
3. Server program should receive the port number as command-line argument. Syntax: `./server_name port_num` Eg: `./server 2999`.
4. Client program should receive the server’s IP address, port number and the filename as command-line argument. Syntax: `./client_name ip_address_of_server port_num file_name` Eg: `./client localhost 2999 hello.c`
---
### **Assignment-2**: Write a ‘C’ program to create a unix shell environment. The shell should implement following features:
1. The shell should run continuously, and display a prompt (>, similar to $)
2. Waiting for input. Include the full path of the current directory also in the prompt.
3. Implement the “>” sign (for ex., /usr/home/me/Desktop>).
4. The shell should read a line from input one at a time.
5. After parsing the command, the shell should execute it.
>Here are the following commands that need to be executed: `clear` `env` `cd` `ls` `pwd` `mkdir` `rmdir` `history` history with arguments `history<...>` `exit`
---
### **Assignment-3**: Implement the following CPU Scheduling algorithms
1. Priority Scheduling algorithm
2. Round Robin CPU Scheduling algorithm
Implement the Priority algorithm in Non-Pre-emptive mode. The algorithms should display a table which includes the Process Id, CPU Burst Time, Waiting Time and Turn around time. Also, calculate the Average Waiting Time and Average Turnaround time.
---
### **Assignment-4**: Implement the Dining Philosophers problem using Java. The program should ask the user to enter the number of Philosophers want to eat simultaneously and it should provide a sequence of steps to by which the philosophers eat. If the input is 5, it should result in dead lock.
> Use the Semaphore class from the package java.util.concurrent
```
private static Semaphore chopsticks [] = new Semaphore [5];
//Initialize the following through the constructor
chopsticks[0] = new Semaphore(1);
chopsticks[1] = new Semaphore(1);
chopsticks[2] = new Semaphore(1);
chopsticks[3] = new Semaphore(1);
chopsticks[4] = new Semaphore(1);

//use tryAcquire() method in the Semaophore class to acquire the chopstick.
boolean left = chopsticks[phNo].tryAcquire(); //acquires left chopstick if free and returns true, else returns false
boolean right = chopsticks[ ((phNo+1)%5) ].tryAcquire(); //acquires right chopstick if free and returns true, else returns false
chopsticks[phNo].release(); //release the left chopstick
chopsticks[ ((phNo+1)%5)].release(); //release the right chopstick
```
---
### **Assignment-5**: Implement Banker’s algorithm. Let ‘n’ refers the number of processes and ‘m’ refers the number of resources. (Read ‘n’ and ‘m’ as inputs from user). Define the following data structures.
1. Available [m] of size ‘m’, such that Available[j] = k refers that ‘k’ instance of resource ‘j’ is available. (Read as user input)
2. Max[n][m], such that Max[i][j]=k, means that Process ‘i’ can demand maximum ‘k’ instance of resource ‘j’. (Read as user input)
3. Allocation[n][m] such that Allocation[i][j]=k, means currently ‘k’ instances of resource ‘j’ is allocated to process ‘i’. (Read as user input)
4. Need[n][m] – To be calculated. Calculate Need[i][j], such that Need[i][j] = Max[i][j] – Allocation[i][j]
5. Display Max, Allocation, Available and Need for all processes.
6. Take new Resource Request as user input for any particular process and check. (Request[m] – Take as user input, PNo – Take as user input).
7. If Request > Need then display an Error, as “The Request exceeded Max Limit” and quit.
8. If Request > Available then display as “Currently, Sufficient resources are not available, the process should wait” and quit.
9. If above two options are not satisfied then update Allocation, Need and Available and then display the updated values of Max, Allocation, Available and Need data structures for all processes. Allocation[PNo][j] = Allocation[PNo][j] + Request[j] Need[PNo][j] = Need[PNo][j] – Request[j] Available[j] = Available[j] – Request[j]

---

### **Assignment-6** Q1: Read the size of logical memory and page size as bytes from user. Do the following
1. Identify the no. of entries in the page table. Read the respective frame number for every page number as user input and populate the page table.
2. Display the page table.
3. Read a logical address as Input from the user and identify the page_no, offset and physical address corresponding to that logical address.
### Q2: Read the following as user inputs: values of PTBR as bytes, value of PTLR as bytes, page size as KB, page number that is to be accessed. 
> Identify whether the requested page is valid (V) or not (I). (i.e. the valid bit corresponding to that page will be set as ‘v’ or as ‘i’).
### Q3: Read the following values as user input: The number of users, the size of code space of the reentrant code as KB, the size of the data space of the reentrant code in KB.
> Identify the total space required with shared pages and without using shared pages?
















