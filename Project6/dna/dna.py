from sys import argv
from csv import reader,DictReader

if len(argv)!=3:
    print('Usage: python dna.py data.csv sequence.txt')
    exit()

#read the dna sequence from file
with open(argv[2]) as text:
    dnaread = reader(text)
    for row in dnaread:
        dnalist = row

sequences={}
dna=dnalist[0]
with open(argv[1]) as database:
    people = reader(database)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break

for item in dnaSequences:
    sequences[item] = 1

for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):
        while temp > 0:
            temp -= 1
            continue
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                temp += 1
                i += l

            if temp > tempMax:
                tempMax = temp

    sequences[key] += tempMax

with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0

        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()

    print("No match")