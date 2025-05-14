#include <iostream>
#include <string>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <exception>
#include <filesystem>
#include <unistd.h>

std::string getIPAddress(){
    std::string ipAddress="Unable to get IP Address";
    struct ifaddrs *interfaces = NULL;
    struct ifaddrs *temp_addr = NULL;

    if (getifaddrs(&interfaces) == 0) {
        temp_addr = interfaces;
        while(temp_addr != NULL) {
            if(temp_addr->ifa_addr->sa_family == AF_INET) {
                std::string interfaceName(temp_addr->ifa_name);
                if(interfaceName.find(std::string("enx")) != std::string::npos) {
                    ipAddress = inet_ntoa(((struct sockaddr_in*)temp_addr->ifa_addr)->sin_addr);
                }
            }
            temp_addr = temp_addr->ifa_next;
        }
    }
    freeifaddrs(interfaces);
    return ipAddress;
}

void copyConfigToDirectory(bool inOffice) {
    std::string userName(getlogin());
    std::string destination = "/home/" + userName + "/.config/evolution/sources/system-proxy.source";
    auto currentDir = std::filesystem::current_path();

    if(inOffice) {
        std::filesystem::copy(currentDir / "evolution-no-proxy.conf", destination,
            std::filesystem::copy_options::overwrite_existing);
    } else {
        std::filesystem::copy(currentDir / "evolution-with-proxy.conf", destination,
            std::filesystem::copy_options::overwrite_existing);
    }
    std::cout << "Proxy: " << std::boolalpha << !inOffice << std::endl;
}

int main() {
    std::string ip = getIPAddress();

    if(ip.find(std::string("143.50.")) != std::string::npos) {
        copyConfigToDirectory(true);
    } else {
        copyConfigToDirectory(false);
    }
    return 0;
}