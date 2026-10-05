class Playlist {
    constructor(name, createdOn, isPublic) {
        this.name = name;
        this.createdOn = createdOn;
        this.isPublic = isPublic;
        this.songs = [];
    }

    togglePublic() {
        this.isPublic = !this.isPublic;
    }

    addSong(songTitle) {
        this.songs.push(songTitle);
    }
}

const playlist = new Playlist(
    "My Favorites",
    new Date("2026-10-05"),
    true
);

playlist.addSong("Perfect");
playlist.addSong("Shape of You");
playlist.addSong("Believer");

console.log("Playlist:", playlist.name);
console.log("Songs:");

playlist.songs.forEach((song, index) => {
    console.log(`${index + 1}. ${song}`);
});
