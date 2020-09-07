/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <pwd.h>
#include <ctime>
#include <memory>

#include <src/Syntax/Settings.hpp>
#include <src/Syntax/FileFunction.hpp>
#include <src/Syntax/Log.hpp>
#include <src/synflang.hpp>
#include <src/Scrift.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <StringTools.h>
#include <Colorized.hpp>
#include <StringTools.h>

std::unique_ptr<FileFunction::FCreateFileFunction> createfile(new FileFunction::FCreateFileFunction);
std::unique_ptr<FileFunction::FReadFileFunction> readfile(new FileFunction::FReadFileFunction);


/*
	.scrift_settings
*/
std::string
FSettings::Path() {
    std::string Path;
    Path.append(getenv("HOME"));
    Path.append("/");
    return Path.append(".scrift_settings");
}

std::string GPath() {
	FSettings pth;
	return pth.Path();
}

std::ifstream freadfile(GPath());


/*
	welcome_message yes: Shows Welcome message
		* Welcome to Fegeya Scrift Terminal
		* Fegeya Scrift licensed with MIT License
		* Copyright (c) 2020 Ferhat Gecdogan

	welcome_message no_thanks:
*/

bool
FSettings::WelcomeMessage() {
	std::string line = fsplusplus::FindStringWithReturn(Path(), "welcome_message");
	if(strstr(line.c_str(), "no_thanks"))
		return false;
 	else
		return true;

	return true;
}

/*
	local_git_branch yes
		... [develop]

	local_git_branch no_thanks
		...
*/

bool
FSettings::GitBranch() {
	std::string line = fsplusplus::FindStringWithReturn(Path(), "local_git_branch");
	if(strstr(line.c_str(), "no_thanks"))
		return false;
	else
		return true;

	return true;
}

/*
        scrift_setup yes
        scrift_setup no
*/
bool
FSettings::Setup() {
        std::string line = fsplusplus::FindStringWithReturn(Path(), "scrift_setup");
        if(strstr(line.c_str(), "yes"))
                return true;
        else
                return false;

        return true;
}

/*
	<emoji> emoji: Shows emoji.
*/
std::string
FSettings::FWelcomeEmoji() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "welcome_emoji");
    return stringtools::EraseAllSubString(line, "welcome_emoji ");
}

/*
	<felog> value: Clears your Felog history if Felog line more than value.
*/
int
FSettings::FeLogCleaner() {
   std::string line = fsplusplus::FindStringWithReturn(Path(), "felog_cleaner");

   if(atoi(stringtools::EraseAllSubString(line, "felog_cleaner ").c_str()) <= 5) {
	colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), "felog_cleaner : Give 5 or higher value.\n");
   	return 20;
   } else return atoi(stringtools::EraseAllSubString(line, "felog_cleaner ").c_str());

    return 100;
}

int
FSettings::random(int min_num, int max_num) {
    srand(time(0));
    return rand() % (max_num - min_num + 1 ) + min_num;
}

int
FSettings::color() {
    int x = random(0, 2);
    if(x == 1)
    	return random(30, 37);
    else if(x == 2)
    	return random(90, 97);
    else if(x == 0)
    	return random(30, 37);

    return random(90, 97);
}

/*
	<asciiart> no_thanks: Not shows ASCIIArt.
	<asciiart> random: Shows ASCIIArt with random color.
	<asciiart> <value>: Shows ASCIIArt with <value>.
*/
int
FSettings::ASCIIColor() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "ascii_art_color");
    if(strstr(line.c_str(), "no_thanks")) {
	return -1;
    } else if(strstr(line.c_str(), "random")) {
	return color();
    } else if(atoi(stringtools::EraseAllSubString(line, "ascii_art_color ").c_str()) <= 29) {
	colorized::PrintWith(colorized::Colorize(BOLD, RED).c_str(), "ascii_art_color : Give 30 or higher value.\n");
	return 34;
    } else {
	return atoi(stringtools::EraseAllSubString(line, "ascii_art_color ").c_str());
    }

    return 34;
}

/*
	Background color.
*/
int
FSettings::BackgroundColor() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "bg_color");
    return atoi(stringtools::EraseAllSubString(line, "bg_color ").c_str());
}

/*
	default: input color is a lot of colors!
	classic: input color is light white.
*/
std::string
FSettings::Theme() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "scrift_theme");
    if(strstr(line.c_str(), "default"))
	return "default";
    else if(strstr(line.c_str(), "classic"))
	return "classic";
    else
	return "default";

    return "default";
}

/*
	<username>@<hostname>:~<path> (input_customize)
*/
std::string
FSettings::InputCustomize() {
    std::string line = fsplusplus::FindStringWithReturn(Path(), "input_customize");
    line = stringtools::EraseAllSubString(line, "input_customize ");
    return stringtools::EraseAllSubString(line, "\n");
}
