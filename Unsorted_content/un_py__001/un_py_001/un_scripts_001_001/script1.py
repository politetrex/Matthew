palindrome = "amanaplanacanalpanama"
def px2():
    global palindrome
    palin2=palindrome[1:]
    palindrome=palindrome[::-1]+palin2
for i in range(5): px2()
print(palindrome)