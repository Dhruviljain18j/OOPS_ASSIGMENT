class Playlist {
    constructor(name, createdOn, isPublic) {
        this.name = name;
        this.createdOn = createdOn;
        this.isPublic = isPublic;
    }

    togglePublic() {
        this.isPublic = !this.isPublic;
    }
}

const playlist = new Playlist(
    "My Favorites",
    new Date("2026-10-05"),
    true
);

console.log("Initial:", playlist.isPublic);

playlist.togglePublic();
console.log("After first toggle:", playlist.isPublic);

playlist.togglePublic();
console.log("After second toggle:", playlist.isPublic);
