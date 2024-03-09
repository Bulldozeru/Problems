Here are requirements after I built passwordChecker.cpp

6 <= password.length() <= 50

Password must contain at least one character from each string
    Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" // 26
    Lowercase = "abcdefghijklmnopqrstuvwxyz" // 26
    Digits    = "0123456789" // 10
    Symbols   = "`~!@#$%^&*()-=_+|,./;':<>?" // 26
    
TOTAL CHARACTERS = 88

I changed the requirements a bit from those of the Leetcode because it extended the time for brute-forcing the password
To give you 3 examples here are the amount of passwords with 6, 10, 16 charactes

6^88 = 300130432287774181063866491774976356909000436905858313406982721110016
8^88 = 29642774844752946028434172162224104410437116074403984394101141506025761187823616
16^88 = 9173994463960286046443283581208347763186259956673124494950355357547691504353939232280074212440502746218496 

Any character can be Uppercase, Lowercase, Digit or a Symbol so is the number of characters, say x, to  the power of 88
x = password.length()
possible passwords = x^88

A cryptography key is considered secure when is above 90 bits 2^90
6^88 is a bit lower than 2^230

It will take more than a billion of years to brute-force it
