# Virtue: Project Design Document

## 1. Executive Summary
**Virtue** is a community-driven, open-source Role-Playing Game (RPG) designed as a spiritual successor to the legendary *Ultima* series. Built on **Unreal Engine 5**, Virtue aims to modernize the classic CRPG experience while preserving the deep moral philosophy, world interactivity, and open-ended exploration that defined the genre.

This project is unique in its **"Open Contribution"** philosophy, welcoming contributors of all skill levels—from manual coders and level designers to lore writers and playtesters.

## 2. World Building: The Realm of **Veridia**
*(Note: "Veridia" is a proposed copyright-safe name, derived from 'Veritas' for Truth, symbolizing the quest for virtue)*

### 2.1 Setting
Veridia is a land of fractured ideals, recovering from a cataclysm known as "The Discordance." Unlike the singular rule of Britannia, Veridia is governed by the **Circle of Principles**.

### 2.2 The Paragons
Players do not take on the role of an "Avatar." Instead, they are **Paragons**—champions summoned from other worlds to restore balance to the virtues of Veridia.
*   **Default Prototype Character**: **Helga**, a female Paragon.

### 2.3 Locations
*   **The Virtue Swirl**: The multiverse's only 24/7 confectionery and bakery. Famous for its hypnotic, cinnamon-infused pastries that restore stamina and morale. A copyright-safe homage to the "warp zones" or beloved hangouts of old.

## 3. Core Gameplay Pillars

### 3.1 The Three Prototypes
To ensure polished gameplay mechanics, development will proceed through three distinct prototyping phases:

1.  **Prototype A: "The Tactician" (Top-Down)**
    *   **View**: Iso-metric / Orthographic top-down camera (classic CRPG style).
    *   **Focus**: Tile-based movement logic, world interaction, conversation systems, and turn-based or real-time-with-pause combat.
    *   **Goal**: Nail the "spirit" of the classic feel.

2.  **Prototype B: "The Explorer" (Immersive 3D)**
    *   **View**: First-Person (FPS) and Third-Person (Over-the-shoulder).
    *   **Focus**: UE5 Nanite/Lumen visuals, real-time combat mechanics, immersion, physics-based object manipulation.
    *   **Goal**: Leverage the power of UE5 for modern presentation.

3.  **Prototype C: "The Virtue" (Unified Experience)**
    *   **View**: Seamless dynamic zoom.
    *   **Mechanic**: Mouse wheel scrolls from a tactical top-down view all the way into the eyes of the Paragon (First-Person).
    *   **Goal**: The final intended gameplay loop, combining tactical oversight with immersive exploration.

### 3.2 The Virtue System
The game tracks the player's actions against a set of new, non-infringing virtues (e.g., *Valor, Wisdom, Compassion* -> *Bravery, Insight, Empathy*). NPCs react dynamically to the Paragon's moral standing.

### 3.3 The Spirit of the Ancients (Core Features)
To truly succeed the classics, **Virtue** must implement these beloved, non-negotiable features:

#### A. The Living World (Hyper-Interactivity)
*   **"If you can see it, you can touch it."** Every object in the world must be interactive.
    *   *Example*: Drag flour to a table, use water on it to make dough, put dough in an oven to bake bread.
    *   *Physics*: Objects can be stacked, thrown, or arranged to solve puzzles (e.g., stacking boxes to climb a wall).
    *   *Crafting*: No menus-only crafting. Crafting happens in the world (e.g., hammering a glowing ingot on an anvil).

#### B. Biological NPC Schedules
*   NPCs are not statues waiting for quest interaction.
*   **Day/Night Cycle**: NPCs wake up, eat breakfast, walk to work, open their shops, close for lunch, go to the tavern in the evening, and sleep at night.
*   **Agency**: Alternatively, shopkeepers will NOT sell to you if they are asleep or eating lunch. Breaking into their house at night is a crime (lowers Integrity).

#### C. Moral Consequences (Invisible Karma)
*   **No "Game Over" for being bad**: Just a harder world.
*   **Tracking**: The game secretly tracks metrics like "Theft", "Aggression", "Charity".
*   **Reaction**: If a Paragon steals, guards might not attack immediately, but prices in shops will rise, or citizens will refuse to speak to them ("I hear you are untrustworthy").

#### D. No Quest Markers
*   **Exploration-First**: Players must listen to dialogue, read journals, and observe the world.
*   **The Journal**: An auto-updating diary that records *what was said*, not *what to do*.

## 4. Technical Architecture

*   **Engine**: Unreal Engine 5 (UE5)
*   **Target Platforms**: Linux, Windows, macOS
*   **Language**: C++ (Core Systems), Blueprints (Content/Scripting)
*   **Asset Pipeline**: 
    *   Use of AI-generated placeholders for rapid prototyping (textures, voice lines, lore drafts).
    *   Community-driven asset replacement for final polish.

## 5. Community & Contribution
*   **Philosophy**: "From Coder to Storyteller."
*   **Tools**:
    *   **Lore Bible**: A wiki-style repository for writers.
    *   **Blueprint Sandboxes**: For non-coders to design logic.
    *   **AI Assistants**: To help generate boilerplate code or asset variations.

## 6. Immediate Next Steps
1.  **Lore Bible Initialization**: Define the 8 Principles of Veridia.
2.  **Asset Acquisition**: Generate "Helga" model and "Virtue Swirl" concept art using AI tools.
3.  **UE5 Project Setup**: Initialize the repository structure.
