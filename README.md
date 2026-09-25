# INJECTOR DIAGNOSTIC

A modular C++17 automotive diagnostics and injector testing foundation.

> **Simulation Mode only:** this project does not connect to a real ECU, OBD-II adapter, CAN bus, or injector test bench. Values and results are simulated and explicitly marked.

## Features
- Simulated live data: RPM, coolant temperature, TPS, MAP, MAF, O2 sensor, battery voltage
- Simulated ECU scan and DTC database
- Injector resistance, pulse, flow, and leak tests
- Step-by-step diagnosis workflow
- Vehicle, ECU, and communication settings
- CMake, C++17, Standard Library only, and CTest unit tests

## Build
```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Run with `./build/injector_diagnostic` on Linux/macOS. This is a development foundation, not certified safety-critical software.
