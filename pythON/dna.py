import csv
import re
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(0)
    people = []
    # TODO: Read database file into a variable
    with open(sys.argv[1], "r") as filePeople:
        reader = csv.DictReader(filePeople)
        for person in reader:
            people.append(person)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as f:
        dnaSequence = f.read()
    # TODO: Find longest match of each STR in DNA sequence
    dna = {}
    dna["AGATC"] = longest_match(dnaSequence, "AGATC")
    dna["AATG"] = longest_match(dnaSequence, "AATG")
    dna["TATC"] = longest_match(dnaSequence, "TATC")
    match = re.search(r'large', sys.argv[1])
    if match:
        dna["TTTTTTCT"] = longest_match(dnaSequence, "TTTTTTCT")
        dna["TCTAG"] = longest_match(dnaSequence, "TCTAG")
        dna["GATA"] = longest_match(dnaSequence, "GATA")
        dna["GAAA"] = longest_match(dnaSequence, "GAAA")
        dna["TCTG"] = longest_match(dnaSequence, "TCTG")

    # TODO: Check database for matching profiles

    for person in people:
        count = 0
        for key, value in dna.items():
            if int(person[key]) == value:
                count += 1

        if count == len(person)-1:
            print(person["name"])
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
