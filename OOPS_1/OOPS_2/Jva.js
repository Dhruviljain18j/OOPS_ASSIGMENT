class Playlist {
    constructor(name, createdOn, isPublic) {
        this.name = name;
        this.createdOn = createdOn;
        this.isPublic = isPublic;
    }
}

const playlist = new Playlist(
    "My Favorites",
    new Date("2026-10-05"),
    true
);

console.log("Playlist Name:", playlist.name);
console.log("Created On:", playlist.createdOn);
console.log("Is Public:", playlist.isPublic);
