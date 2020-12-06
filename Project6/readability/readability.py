from cs50 import get_string

x=get_string('Text: ')
y=len(x)
words=1;
sentences=0;
letters=0;

for character in x:
    if character==' ':
        words=words+1;
    if character=='.' or character=='?' or character=='!':
        sentences=sentences+1
    if (character>='a' and character<='z') or (character>="A" and character<='z'):
        letters=letters+1;
L=(letters/words)*100
S=(sentences/words)*100
CLI=(0.0588*L)-(0.296*S)-15.8
roundedCLI=round(CLI)
if roundedCLI>=16:
    print('Grade 16+')
else:
    print('Grade: ',roundedCLI)

