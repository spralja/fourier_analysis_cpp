cmake_minimum_required(VERSION 3.20)
project(fourier_analysis_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(fourier_analysis_cpp main.cpp FourierAnalysis.cpp FourierAnalysis.h main.cpp TrigonometricFunctionValues.cpp TrigonometricFunctionValues.h Alphas.cpp Alphas.h Coefficient.cpp Coefficient.h CoefficientCollection.cpp CoefficientCollection.h)
