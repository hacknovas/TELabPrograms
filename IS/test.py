string = "Doni"

print('Now converting this string into charecters')

#declare one empty list
lst1=[]
#now convert above string into list
for x in string:
    lst1.append(x)

print('Displaying the charecter list')
print(lst1)

#now convert the charecter list into integer list using ord function
for x in range (len(lst1)):
    c = ord(lst1[x])
    lst1[x] = c
print('Displaying integer list')
print(lst1)

#now XOR of this 127 with each of the element of lst2.
for x in range(len(lst1)):
   c= lst1[x] ^ 127
   lst1[x] = c
print('Displaying the intger list again with XOR 127')
print(lst1)

#now converting this updated integer list into charecters using chr function
for x in range(len(lst1)):
   c= chr(lst1[x])
   lst1[x] = c
print('Displaying the charecter list of updated integer list afte xor operation')
print(lst1)

#now converting this list into string using join function
c = ''.join(lst1)
print('Displaying the string converted from updated charecter list')
print(c)