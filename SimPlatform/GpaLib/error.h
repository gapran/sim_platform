#ifndef ERRORS_H
#define ERRORS_H
#include<string>


using namespace std;

class Error
{
public:
    Error(int id, string location, string message , string description, int start_line, int project_id,string program_line_of_code, string text_check_pannel, string sarif_file_location, string way_to_fix, string element,string rule_id, int repitition);
    int id;
    string location;
    string message ;
    string description;
    int start_line;
    int project_id;
    string text_check_pannel;
    string sarif_file_location;
    string way_to_fix;
    string element;
    int repitition;
    string program_line_of_code;
    string rule_id;
};

#endif // ERRORS_H
