# perf_sim

perf_sim is a RISC-V CPU Performance Simulator, built on top of [**Spike**](https://github.com/riscv-software-src/riscv-isa-sim). This can be used to simulate and experiment with any specific microarchitecture, that implements the RISC-V ISA.

# What is a CPU Performance Simulator?

A CPU Performance Simulator is used to implement, simulate and experiment with a microarchitecture. 

# Why use a CPU Performance Simulator?

One can implement a specific CPU microarchitecture, run simulations against various performance benchmarks/microbenchmarks to conduct experiments.

# What can you run on perf_sim?

Right now, perf_sim can load and run any elf compiled with a RISC-V compiler. As of now I'm using riscv-unknown-elf-gcc to compile.
