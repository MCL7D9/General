while (True):
     pw=input('Please create a password with capital, small letters and numbers.The length should be longer than 8 letters: ')
     symbol=False
     if len(pw)<8:
          print('The password have to be',8-len(pw),'letters longer!')
          continue
     else:
          print('First requirement checked...')
     if str.isdigit(pw)==True:
          print('The password needs English letters!')
          continue
     else:
          print('Second requirement checked...')
     if str.isupper(pw)==True:
          print('The password needs small letters!')
          continue
     else:
          print('Third requirement checked...')
     if str.islower(pw)==True:
          print('The password needs capital letters!')
          continue
     else:
          print('Forth requirement checked...')
     if str.isalpha(pw)==True:
          print('The password needs letters!')
          continue
     else:
          print('Good password!')
     for i in pw:
          if ((not(isdigit(i)))and(not(isalpaha(i)))):
               symbol=True
     if (symbol==False):
          continue
     pw2=input('Please input your password again: ')
     if pw!=pw2:
          print('Mismatch with your password!')
          continue
     else:
          print('Password set successfully!')
    