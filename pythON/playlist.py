import csv

def main():
    min_tempo = int(input("Minimum tempo: "))
    max_tempo = int(input("Maximum tempo: "))   

    playlist = []
    # TODO: Read songs from 2018_top100.csv into playlist
    with open("2018_top100.csv", "r") as songFile:
        reader = csv.DictReader(songFile)
        for song in reader:
            if float(song["tempo"]) >= min_tempo and float(song["tempo"]) <= max_tempo:
                playlist.append(song)

    # TODO: Print song titles from playlist
    for song in playlist:
        print(f"{song['name']}")

main()