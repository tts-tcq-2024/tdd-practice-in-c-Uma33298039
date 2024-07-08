boolean isEmptyStr(const char*input)
{
  if (input == NULL || input[0] == '\0') {
        return TRUE; // The string is empty
    }
  return FALSE;
}
int add (const char*input)
{
  if(isEmptyStr(input) ==TRUE)
{
  return 0;
}
  return 1;
}
