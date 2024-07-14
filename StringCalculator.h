#include <string.h>
#include<stdlib.h>
Bool isemptystring(const char* value)
{
    if (value == NULL || value[0] == '\0')
    {
        return 1;
    }
    return 0;
}
int islessthanthousand(const char *val)
{    
    int sum = 0;
    int value_check = atoi(val);
    if(value_check < 1000)
    {
        sum += value_check;
        return sum;
    }
    return 0;
     
}


void append_custom_delimiter(const char* input, char* delimiter) {
    int i = 2; 
    while(input[i] != '\n')
    {
        char temp[1] = {input[i]};
        strncat (delimiter, temp,1);
        i = i+1;
    }
}

void checkcustomdelimiter(const char* input, char* delimiter)
{
    if (input[0] == '/' && input[1] == '/')
    {
        strcpy(delimiter, "");
        append_custom_delimiter(input,delimiter);
    }
    else
    {
        delimiter = ",\n";
    }
}

int calculatesum(const char* input, char* delimiter)
{
    int sum = 0;
    char* dup_input = NULL;
    dup_input = strdup (input);
    char* input_seg = strtok(dup_input,delimiter);
    while(input_seg != NULL)
    {
        sum = sum + islessthanthousand(input_seg);
        input_seg = strtok(NULL,delimiter);
    }
    return sum;
}

int add (const char* input)
{
    char delimiter[128] = ",\n";
    if (1 == isemptystring(input))
    {
        return 0;
    }
    checkcustomdelimiter(input, delimiter);
    return calculatesum(input, delimiter);
    
}
