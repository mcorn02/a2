#Team Names: Michael Corn and Simmon Quan

#Edoras Usernames: cssc1415 and cssc1450

#Class Info: CS 480 Operating Systems, Summer Session 2 2025

#Assignment #2: Experimental Shell "XSH"

#File Name: Makefile
	

CXX = g++
CXXFLAGS = -Wall -std=c++11 
TARGET = xsh

all: $(TARGET)

$(TARGET): XSH.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) XSH.cpp

clean:
	rm -f $(TARGET) 
