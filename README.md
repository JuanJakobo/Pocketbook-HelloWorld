# Pocketbook Hello World 

## How to Setup

First you need to install the basic build tools for linux.

Then you have to download the Pocketbook SDK (https://github.com/pocketbook/SDK_6.3.0/tree/5.19).

In the CMakeLists.txt of this project you have to set the root of the TOOLCHAIN_PATH to the location where you saved the SDK. 
This could be for example:

`SET (TOOLCHAIN_PATH "../../SDK/SDK_6.3.0/SDK-B288")`

Then you have to setup cmake by:

`cmake .`

To build the application run:

`make` 

## How to go on

A very good tutorial how to set up GDB and program small function is https://github.com/pmartin/pocketbook-demo.

### Tested on
* Pocketbook HD3 (PB623) (V. U623.6.0.926)

## Usage

Once the application is build it can be copied to the Pocketbook to finally use it. 
Therefore you have to copy the file "HelloWorld.app" which is placed in the bin folder to the application folder of the PB.
The App then is placed under User. It simply offers an empty screen. When you click on the screen an star appears. 

## Disclamer

Use as your own risk! 
Even though the possibility is really low, the application could harm your device or even break it.
