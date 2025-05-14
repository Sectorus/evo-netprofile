# Evolution Net Profile
==========================

Evolution Net Profile is a C++ application that determines the IP address of a device and uses it to configure the Evolution email client's proxy settings.

## Features
-----------

* Automatically detects the IP address of the device
* Configures the Evolution email client's proxy settings based on the IP address
* Supports different proxy configurations for in-office and out-of-office scenarios

## How it Works
----------------

The application uses the `getifaddrs` function to retrieve the IP address of the device. It then checks if the IP address matches a specific pattern (in this case, `143.50.*`) to determine whether the device is in the office or not. Based on this determination, it copies either the `evolution-no-proxy.conf` or `evolution-with-proxy.conf` file to the Evolution email client's configuration directory.

## Getting Started
---------------

### Prerequisites

* C++ compiler (e.g. GCC)
* Evolution email client installed on the system

### Installation

* Clone the repository using `git clone https://github.com/Sectorus/evolution-network-setup.git`
* Compile the application using `g++ evolution-network-setup.cpp -o evolution-network-setup`
* Run the application using `./evolution-network-setup`

### Usage

* The application will automatically configure the Evolution email client's proxy settings based on the IP address of the device.

## Contributing
------------

* Fork the repository and make changes to the code
* Submit a pull request with a clear description of the changes

