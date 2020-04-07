#ifndef DEFAULT_SETTINGS_H
#define DEFAULT_SETTINGS_H

#include "Directory.h"
#include "File.h"
#include "main.h"
#include "Path.h"
#include "Sync.h"
#include "Syntax.h"
#include <fstream>

file_sync_t *__file_sync;


 typedef struct FDefaultSettings {
public:
    char *default_file_path = __file_sync->default_file_sync_path;
    char *default_child_file_path =  __file_sync->default_child_file_sync_path;
    char *_lang_ = __file_sync->default_lang;
    char *cpu_name = __file_sync->_cpu_name;
    int64_t *_ram_size_ = __file_sync->ram_size_;
}default_setting_t;


typedef struct FLoad  :  FDefaultSettings {
public:
    default_setting_t *def_settings;
    std::ofstream *setting_init_file;
protected:
    file_sync_t *_sync_to_init_file;
}fload_t;





default_setting_t *def;
fload_t *init;




class FDefaultSettingsClass {
public:
    FDefaultSettingsClass();
    ~FDefaultSettingsClass();
    virtual void LoadDefaultSettings(default_setting_t *__def);
    void LoadSettings(default_setting_t *_def, char *default_username,  char *_default_language); 
protected:
    char *default_f_path = def->default_file_path;
    char *default_child_f_path = def->default_child_file_path;
    char *_language_ = def->_lang_;
    char *cpu_name_ = def->cpu_name;
    int64_t *__ram__size__ = def->_ram_size_;
};



#endif