#!/bin/bash


# Colors
yellow='\033[33;1m'
red='\033[31;1m'
green='\033[32;1m'
reset='\033[0m'	


echo
echo -e "${yellow}------------------------- CONVERT TEST -------------------------"
echo -e "---------------------------------------------------------------"
echo -e "${yellow}			No argument test.."
echo -e "---------------------------------------------------------------${reset}"

echo "./ScalarConverter"
./ScalarConverter

echo -e "${yellow}---------------------------------------------------------------"
echo -e "			Invalid input tests..."
echo -e "---------------------------------------------------------------${reset}"

echo "./ScalarConverter jorge"
./ScalarConverter jorge

echo "./ScalarConverter 123jorge"
./ScalarConverter 123jorge

echo "./ScalarConverter 123.123.123"
./ScalarConverter 123.123.123

echo "./ScalarConverter 123,123,123"
./ScalarConverter 123,123,123


echo -e "${yellow}---------------------------------------------------------------"
echo -e "			Limits tests..."
echo -e "---------------------------------------------------------------${reset}"

echo "./ScalarConverter 2147483647"
./ScalarConverter 2147483647

echo "./ScalarConverter -2147483648"
./ScalarConverter -2147483648

echo "./ScalarConverter 2147483648"
./ScalarConverter 2147483648

echo "./ScalarConverter -2147483649"
./ScalarConverter -2147483649

echo "./ScalarConverter 4294967295"
./ScalarConverter 4294967295

echo "./ScalarConverter -4294967296"
./ScalarConverter -4294967296

echo "./ScalarConverter 4294967296"
./ScalarConverter 4294967296

echo "./ScalarConverter -4294967297"
./ScalarConverter -4294967297

echo "./ScalarConverter 9223372036854775807"
./ScalarConverter 9223372036854775807

echo "./ScalarConverter -9223372036854775808"
./ScalarConverter -9223372036854775808

echo "./ScalarConverter 9223372036854775808"
./ScalarConverter 9223372036854775808

echo "./ScalarConverter -9223372036854775809"
./ScalarConverter -9223372036854775809

echo "./ScalarConverter 18446744073709551615"
./ScalarConverter 18446744073709551615

echo "./ScalarConverter 2147483647.99999999999999"
./ScalarConverter 2147483647.99999999999999

echo "./ScalarConverter -2147483648.99999999999999"
./ScalarConverter -2147483648.99999999999999

echo -e "${yellow}---------------------------------------------------------------"
echo -e "			Char tests..."
echo -e "---------------------------------------------------------------${reset}"

echo "./ScalarConverter 'A'"
./ScalarConverter "A"

echo "./ScalarConverter 'l'"
./ScalarConverter "l"

echo "./ScalarConverter 'e'"
./ScalarConverter "e"

echo "./ScalarConverter 'x'"
./ScalarConverter "x"

echo "./ScalarConverter '/'"
./ScalarConverter "/"

echo "./ScalarConverter '?'"
./ScalarConverter "?"


echo -e "${yellow}---------------------------------------------------------------"
echo -e "			Float tests..."
echo -e "---------------------------------------------------------------${reset}"

echo "./ScalarConverter 123.123"
./ScalarConverter 123.123

echo "./ScalarConverter 123.123f"
./ScalarConverter 123.123f

echo "./ScalarConverter 123.123F"
./ScalarConverter 123.123F

echo "./ScalarConverter 123.123l"
./ScalarConverter 123.123l

echo "./ScalarConverter 123.123L"
./ScalarConverter 123.123L

echo "./ScalarConverter 123.123e10"
./ScalarConverter 123.123e10

echo "./ScalarConverter 123.123e+10"
./ScalarConverter 123.123e+10

echo "./ScalarConverter 123.123e-10"
./ScalarConverter 123.123e-10


echo -e "${yellow}---------------------------------------------------------------"
echo -e "			Double tests..."
echo -e "---------------------------------------------------------------${reset}"

echo "./ScalarConverter 123.123"
./ScalarConverter 123.123

echo "./ScalarConverter 123.123f"
./ScalarConverter 123.123f

echo "./ScalarConverter 123.123F"
./ScalarConverter 123.123F

echo "./ScalarConverter 123.123l"
./ScalarConverter 123.123l

echo "./ScalarConverter 123.123L"
./ScalarConverter 123.123L

echo "./ScalarConverter 123.123e10"
./ScalarConverter 123.123e10

echo "./ScalarConverter 123.123e+10"
./ScalarConverter 123.123e+10


echo -e "${yellow}---------------------------------------------------------------"
echo -e "			Int tests..."
echo -e "---------------------------------------------------------------${reset}"

echo "./ScalarConverter 0"
./ScalarConverter 0

echo "./ScalarConverter 1"
./ScalarConverter 1

echo "./ScalarConverter -1"
./ScalarConverter -1

echo "./ScalarConverter 42"
./ScalarConverter 42

echo "./ScalarConverter 65"
./ScalarConverter 65

echo "./ScalarConverter 314"
./ScalarConverter 314

echo -e "${yellow}---------------------------------------------------------------"
