bool isEmptyStr(const char*input)
{
  if (input == NULL || input[0] == '\0') {
        return true; // The string is empty
    }
  return false;
}
int add (const char*input)
{
  if(isEmptyStr(input) ==true)
{
  return 0;
}
  return 1;
}
