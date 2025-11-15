MPI is a standardized interface for applications to communicate in a distributed memory system.

When an application adopts the MPI communication standard, it becomes *portable* (can be compiled and executed on many different systems). We can then move it from one system to another and expect it to execute deterministically, even if the systems have different underlying characteristics.

MPI allows a programmer to *divide an application into multiple processes*. It assigns each of an application's processes a **rank** a.k.a an unique identifier.

A process learns its rank by calling `MPI_Comm_rank` function, and learns how many processes are executing in the application by calling `MPI_Comm_size`

A process calls `MPI_Send` and specifies the rank of the intended recipient to send a message, and `MPI_Recv` to receive a message.

There are a variety of functions for one process to communicate data to multiple recipients:
- `MPI_Bcast` allows one process to send a message to every other process in the applications with just one function call.
- `MPI_Scatter` and `MPI_Gather` allows one process to divide up an array and distribute the pieces among processes (scatter), operate on the data, then later retrieve all the data to coalesce the results.

> [!important] 
> Because MPI specifies only a set of functions and how they should behave, each system designer can implement MPI's functionality in a way that *matches the capabilities* of their particular system. An example is that a system with interconnect network  that supports broadcasting might be able to implement `MPI_Bcast`

[Install OpenMPI](https://edu.itp.phys.ethz.ch/hs12/programming_techniques/openmpi.pdf)

[Missing shared library - Use sudo ldconfig to resolve if install system-wide](https://askubuntu.com/questions/738667/problem-with-mpicc)


