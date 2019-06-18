#include "error.h"

Error::Error(int id, string location, string message , string description, int start_line, int project_id,string program_line_of_code, string text_check_pannel, string sarif_file_location, string way_to_fix, string element, string rule_id , int repitition)
{
    this->id = id;
    this->location = location;
    this->message = message;
    this->description = description;
    this->start_line = start_line;
    this->project_id = project_id;
    this->text_check_pannel = text_check_pannel;
    this->sarif_file_location = sarif_file_location;
    this->way_to_fix = way_to_fix;
    this->element = element;
    this->repitition = repitition;
    this->rule_id = rule_id;
}
