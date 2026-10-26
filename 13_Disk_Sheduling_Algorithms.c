# Game texture streaming: each texture sits on a disk cylinder (0-199); head starts at 53

H, MAX = 53, 199

TEX = {
    98: "terrain_grass",
    183: "sky_hdr",
    37: "player_skin",
    122: "water_normal",
    14: "ui_atlas",
    124: "rock_albedo",
    65: "tree_leaves",
    67: "fx_smoke"
}

R = list(TEX)  # requests in the order the game asked for them

up = sorted(c for c in R if c >= H)       # textures ahead of the head (ascending)
down = sorted((c for c in R if c < H), reverse=True)  # textures behind the head (descending)


def sstf(h=H, left=R[:]):
    # Always pick the closest pending texture
    out = []

    while left:
        out.append(min(left, key=lambda c: abs(c - h)))
        h = out[-1]
        left.remove(h)

    return out


PATHS = {
    "FCFS": R,
    "SSTF": sstf(),
    "SCAN": up + [MAX] + down,             # go to the end, then reverse
    "C-SCAN": up + [MAX, 0] + down[::-1],  # go to the end, jump to 0, sweep up again
    "LOOK": up + down,                     # like SCAN but turn at last request
    "C-LOOK": up + down[::-1]              # like C-SCAN but jump to lowest request
}

for name, path in PATHS.items():
    seek = sum(abs(a - b) for a, b in zip([H] + path, path))

    print(f"{name:7} total seek = {seek:3}  avg = {seek / len(R):5.1f}")
    print("        load order:", [TEX.get(c, f"<edge {c}>") for c in path])