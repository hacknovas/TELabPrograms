str = input("Enter Your String:\t")
arr = list(str)
size = len(arr)
print(arr, "\n")

arr1 = []
for x in arr:
    arr1.append(ord(x)) #convert into ascii
print("ASCII :\t", arr1, "\n")

arr2 = []
for i in arr1:
    arr2.append(i ^ 127)  #XOR then integer
print("XOR :\t", arr2, "\n")

arr3 = []
for x in arr2:
    arr3.append(chr(x))
print("Character :\t", arr3, "\n") #binary to Character

result="".join(arr3)

print("\nResult:",result)























# str = input("Enter Your String:\t")
# arr = list(str)
# size = len(arr)
# print(arr, "\n")

# arr1 = []
# for x in arr:
#     arr1.append(ord(x)) #convert into ascii
# print("ASCII :\t", arr1, "\n")

# arr2 = []
# for x in arr1:
#     arr2.append(int(bin(x).replace("0b", ""))) #convert to binary
# print("Binary :\t", arr2, "\n")

# arr3 = []
# for i in arr2:
#     arr3.append(i ^ 127)  #XOR then integer
# print("XOR :\t", arr3, "\n")

# def binaryTodecimal(n):
#     decimal = 0
#     power = 1
#     while n > 0:
#         rem = n % 10
#         n = n // 10
#         decimal += rem * power
#         power = power * 2

#     return decimal

# arr4 = []
# for x in arr3:
#     arr4.append(binaryTodecimal(x))
# print("Decimal :\t", arr4, "\n") #binary to decimal

# arr5 = []
# for x in arr4:
#     arr5.append(chr(x))
# print("Character :\t", arr5, "\n") #binary to Character
