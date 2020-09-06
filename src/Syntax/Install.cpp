/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>
#include <iomanip>

#include <src/Syntax/Install.hpp>
#include <src/Scrift.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>
#include <StringTools.h>

void HelpFunction();

/*
	TODO: Loading bar?
*/

void
FInstall::InstallFetcheya() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/fetcheya") == false) {
		#ifdef __FreeBSD__
			std::cout << "Use this command as super user.\n";
		#else		
			std::cout << "Fetcheya is not installed.\nDo you want to install Fetcheya from source? (y/n) : ";	
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/fetcheya.git");
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/fetcheya");
							std::cout << "Directory changed. : " << getenv("HOME") << "/fetcheya\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh");
							
							if(fsplusplus::IsExistFile("/bin/fetcheya") == true) {
								std::cout << "Installed!\n";
							}
						} else
							std::cout << "gcc not found. Aborted.\n";
					} else
						std::cout << "g++ not found. Aborted.\n";						
				} else
					std::cout << "git not found. Aborted.\n";
			} else
				std::cout << "Aborted.\n";	
		#endif
	} else {
		std::cout << "Fetcheya is already installed\nWould you like to run it? (y/n) : "; 
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("fetcheya");
		else
			std::cout << "Aborted.\n";
	}
}

void
FInstall::InstallFlaScript() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/fla") == false) {
		#ifdef __FreeBSD__
			std::cout << "Use this command as super user.\n";
		#else		
			std::cout << "FlaScript is not installed.\nDo you want to install FlaScript from source? (y/n) : ";	
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/flascript.git");
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/flascript");
							std::cout << "Directory changed. : " << getenv("HOME") << "/flascript\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh");
							
							if(fsplusplus::IsExistFile("/bin/fla") == true) {
								std::cout << "\nInstalled!\n";
							}
						} else
							std::cout << "gcc not found. Aborted.\n";
					} else
						std::cout << "g++ not found. Aborted.\n";						
				} else
					std::cout << "git not found. Aborted.\n";
			} else
				std::cout << "Aborted.\n";	
		#endif
	} else {
		std::cout << "FlaScript is already installed\nWould you like to run it? (y/n) : "; 
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("fla");
		else
			std::cout << "Aborted.\n";
	}
}

void
FInstall::InstallCopyboard() {
	ExecutePlusPlus exec;
	if(fsplusplus::IsExistFile("/bin/copyboard") == false) {
		#ifdef __FreeBSD__
			std::cout << "Use this command as super user.\n";
		#else		
			std::cout << "Copyboard is not installed.\nDo you want to install Copyboard from source? (y/n) : ";	
			char input = getchar();
			if(input == 'y' || input == 'Y') {
				if(fsplusplus::IsExistFile("/bin/git") == true) {
					chdir(getenv("HOME"));
					exec.RunFunction("git clone https://github.com/ferhatgec/copyboard.git");
					if(fsplusplus::IsExistFile("/bin/g++") == true) {
						if(fsplusplus::IsExistFile("/bin/gcc") == true) {
							std::string path(getenv("HOME"));
							path.append("/copyboard");
							std::cout << "Directory changed. : " << getenv("HOME") << "/copyboard\n";
							chdir(path.c_str());
							std::cout << "Installing..\n";
							exec.RunFunction("sudo sh install.sh");
							
							if(fsplusplus::IsExistFile("/bin/copyboard") == true) {
								std::cout << "\nInstalled!\n";
							} else
								std::cout << "Could not load.\n";
						} else
							std::cout << "gcc not found. Aborted.\n";
					} else
						std::cout << "g++ not found. Aborted.\n";						
				} else
					std::cout << "git not found. Aborted.\n";
			} else
				std::cout << "Aborted.\n";	
		#endif
	} else {
		std::cout << "Copyboard is already installed\nWould you like to run it? (y/n) : "; 
		char input = getchar();
		if(input == 'y' || input == 'Y')
			exec.RunFunction("copyboard");
		else
			std::cout << "Aborted.\n";
	}
}

/*
	Simple git-based package installer for Fegeya Community's applications. (Build & Install)
*/
void
FInstall::FegeyaPackageInstaller(std::string arg) {
	/* --i fetcheya */
	if(strstr(arg.c_str(), "--i")) {
		std::cout << "Checking..\n";
		arg = stringtools::EraseAllSubString(arg, "fpi --i ");
		if(strstr(arg.c_str(), "fetcheya")) InstallFetcheya();
		else if(strstr(arg.c_str(), "flascript")) InstallFlaScript();
		else if(strstr(arg.c_str(), "copyboard")) InstallCopyboard();
		else
			std::cout << "No match for this argument : " << arg + "\n";
	} else
		HelpFunction();
}

void HelpFunction() {
	std::cout << "Fegeya Package Installer (fpi)\nUsage: fpi [--i] <app>\n<app> : fetcheya, flascript, copyboard\n";
}
