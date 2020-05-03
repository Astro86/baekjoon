isFBI = False

for i in range(5):
    code_name = input()
    if(code_name.find("FBI") != -1):
        print(i+1, end=' ')
        isFBI = True

if(isFBI == False):
    print("HE GOT AWAY!")
