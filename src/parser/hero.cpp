#include <algorithm>
#include <string>
#include <vector>

#include "hero.h"

// Restricted constructor, creates the Hero with specified id
// Create a empty Hero placeholder if no hero with such id
Hero::Hero(uint32_t id, std::string code_name, std::string formated_name) :
  id_{ id },
  code_name_{ code_name },
  formated_name_{ formated_name }
{
}

// Copy constructor
Hero::Hero(const Hero& hero) :
  id_{ hero.GetId() },
  code_name_{ hero.GetCodeName() },
  formated_name_{ hero.GetFormatedName() }
{
}

// Only public constructor
// Creates the Hero with specified id
// Create a empty Hero placeholder if no hero with such id
Hero::Hero(uint32_t id) {
  auto result = std::find_if(Hero::heroes_.begin(),
    Hero::heroes_.end(),
    [&id](const Hero& hero) { return hero.GetId() == id; });
  if (result != Hero::heroes_.end()) {
    id_ = result->GetId();
    code_name_ = result->GetCodeName();
    formated_name_ = result->GetFormatedName();
  }
  else {
    id_ = Hero::heroes_[0].GetId();
    code_name_ = Hero::heroes_[0].GetCodeName();
    formated_name_ = Hero::heroes_[0].GetFormatedName();
  }
}

// All valid heroes
std::vector<Hero> Hero::heroes_ = {
  { 0, "empty", "Empty" },
  { 1, "npc_dota_hero_antimage", "Anti-Mage" },
  { 2, "npc_dota_hero_axe", "Axe" },
  { 3, "npc_dota_hero_bane", "Bane" },
  { 4, "npc_dota_hero_bloodseeker", "Bloodseeker" },
  { 5, "npc_dota_hero_crystal_maiden", "Crystal Maiden" },
  { 6, "npc_dota_hero_drow_ranger", "Drow Ranger" },
  { 7, "npc_dota_hero_earthshaker", "Earthshaker" },
  { 8, "npc_dota_hero_juggernaut", "Juggernaut" },
  { 9, "npc_dota_hero_mirana", "Mirana" },
  { 10, "npc_dota_hero_morphling", "Morphling" },
  { 11, "npc_dota_hero_nevermore", "Shadow Fiend" },
  { 12, "npc_dota_hero_phantom_lancer", "Phantom Lancer" },
  { 13, "npc_dota_hero_puck", "Puck" },
  { 14, "npc_dota_hero_pudge", "Pudge" },
  { 15, "npc_dota_hero_razor", "Razor" },
  { 16, "npc_dota_hero_sand_king", "Sand King" },
  { 17, "npc_dota_hero_storm_spirit", "Storm Spirit" },
  { 18, "npc_dota_hero_sven", "Sven" },
  { 19, "npc_dota_hero_tiny", "Tiny" },
  { 20, "npc_dota_hero_vengefulspirit", "Vengeful Spirit" },
  { 21, "npc_dota_hero_windrunner", "Windranger" },
  { 22, "npc_dota_hero_zuus", "Zeus" },
  { 23, "npc_dota_hero_kunkka", "Kunkka" },
  { 25, "npc_dota_hero_lina", "Lina" },
  { 26, "npc_dota_hero_lion", "Lion" },
  { 27, "npc_dota_hero_shadow_shaman", "Shadow Shaman" },
  { 28, "npc_dota_hero_slardar", "Slardar" },
  { 29, "npc_dota_hero_tidehunter", "Tidehunter" },
  { 30, "npc_dota_hero_witch_doctor", "Witch Doctor" },
  { 31, "npc_dota_hero_lich", "Lich" },
  { 32, "npc_dota_hero_riki", "Riki" },
  { 33, "npc_dota_hero_enigma", "Enigma" },
  { 34, "npc_dota_hero_tinker", "Tinker" },
  { 35, "npc_dota_hero_sniper", "Sniper" },
  { 36, "npc_dota_hero_necrolyte", "Necrophos" },
  { 37, "npc_dota_hero_warlock", "Warlock" },
  { 38, "npc_dota_hero_beastmaster", "Beastmaster" },
  { 39, "npc_dota_hero_queenofpain", "Queen of Pain" },
  { 40, "npc_dota_hero_venomancer", "Venomancer" },
  { 41, "npc_dota_hero_faceless_void", "Faceless Void" },
  { 42, "npc_dota_hero_skeleton_king", "Wraith King" },
  { 43, "npc_dota_hero_death_prophet", "Death Prophet" },
  { 44, "npc_dota_hero_phantom_assassin", "Phantom Assassin" },
  { 45, "npc_dota_hero_pugna", "Pugna" },
  { 46, "npc_dota_hero_templar_assassin", "Templar Assassin" },
  { 47, "npc_dota_hero_viper", "Viper" },
  { 48, "npc_dota_hero_luna", "Luna" },
  { 49, "npc_dota_hero_dragon_knight", "Dragon Knight" },
  { 50, "npc_dota_hero_dazzle", "Dazzle" },
  { 51, "npc_dota_hero_rattletrap", "Clockwerk" },
  { 52, "npc_dota_hero_leshrac", "Leshrac" },
  { 53, "npc_dota_hero_furion", "Nature\'s Prophet" },
  { 54, "npc_dota_hero_life_stealer", "Lifestealer" },
  { 55, "npc_dota_hero_dark_seer", "Dark Seer" },
  { 56, "npc_dota_hero_clinkz", "Clinkz" },
  { 57, "npc_dota_hero_omniknight", "Omniknight" },
  { 58, "npc_dota_hero_enchantress", "Enchantress" },
  { 59, "npc_dota_hero_huskar", "Huskar" },
  { 60, "npc_dota_hero_night_stalker", "Night Stalker" },
  { 61, "npc_dota_hero_broodmother", "Broodmother" },
  { 62, "npc_dota_hero_bounty_hunter", "Bounty Hunter" },
  { 63, "npc_dota_hero_weaver", "Weaver" },
  { 64, "npc_dota_hero_jakiro", "Jakiro" },
  { 65, "npc_dota_hero_batrider", "Batrider" },
  { 66, "npc_dota_hero_chen", "Chen" },
  { 67, "npc_dota_hero_spectre", "Spectre" },
  { 68, "npc_dota_hero_ancient_apparition", "Ancient Apparition" },
  { 69, "npc_dota_hero_doom_bringer", "Doom" },
  { 70, "npc_dota_hero_ursa", "Ursa" },
  { 71, "npc_dota_hero_spirit_breaker", "Spirit Breaker" },
  { 72, "npc_dota_hero_gyrocopter", "Gyrocopter" },
  { 73, "npc_dota_hero_alchemist", "Alchemist" },
  { 74, "npc_dota_hero_invoker", "Invoker" },
  { 75, "npc_dota_hero_silencer", "Silencer" },
  { 76, "npc_dota_hero_obsidian_destroyer", "Outworld Devourer" },
  { 77, "npc_dota_hero_lycan", "Lycan" },
  { 78, "npc_dota_hero_brewmaster", "Brewmaster" },
  { 79, "npc_dota_hero_shadow_demon", "Shadow Demon" },
  { 80, "npc_dota_hero_lone_druid", "Lone Druid" },
  { 81, "npc_dota_hero_chaos_knight", "Chaos Knight" },
  { 82, "npc_dota_hero_meepo", "Meepo" },
  { 83, "npc_dota_hero_treant", "Treant Protector" },
  { 84, "npc_dota_hero_ogre_magi", "Ogre Magi" },
  { 85, "npc_dota_hero_undying", "Undying" },
  { 86, "npc_dota_hero_rubick", "Rubick" },
  { 87, "npc_dota_hero_disruptor", "Disruptor" },
  { 88, "npc_dota_hero_nyx_assassin", "Nyx Assassin" },
  { 89, "npc_dota_hero_naga_siren", "Naga Siren" },
  { 90, "npc_dota_hero_keeper_of_the_light", "Keeper of the Light" },
  { 91, "npc_dota_hero_wisp", "Io" },
  { 92, "npc_dota_hero_visage", "Visage" },
  { 93, "npc_dota_hero_slark", "Slark" },
  { 94, "npc_dota_hero_medusa", "Medusa" },
  { 95, "npc_dota_hero_troll_warlord", "Troll Warlord" },
  { 96, "npc_dota_hero_centaur", "Centaur Warrunner" },
  { 97, "npc_dota_hero_magnataur", "Magnus" },
  { 98, "npc_dota_hero_shredder", "Timbersaw" },
  { 99, "npc_dota_hero_bristleback", "Bristleback" },
  { 100, "npc_dota_hero_tusk", "Tusk" },
  { 101, "npc_dota_hero_skywrath_mage", "Skywrath Mage" },
  { 102, "npc_dota_hero_abaddon", "Abaddon" },
  { 103, "npc_dota_hero_elder_titan", "Elder Titan" },
  { 104, "npc_dota_hero_legion_commander", "Legion Commander" },
  { 105, "npc_dota_hero_techies", "Techies" },
  { 106, "npc_dota_hero_ember_spirit", "Ember Spirit" },
  { 107, "npc_dota_hero_earth_spirit", "Earth Spirit" },
  { 108, "npc_dota_hero_abyssal_underlord", "Underlord" },
  { 109, "npc_dota_hero_terrorblade", "Terrorblade" },
  { 110, "npc_dota_hero_phoenix", "Phoenix" },
  { 111, "npc_dota_hero_oracle", "Oracle" },
  { 112, "npc_dota_hero_winter_wyvern", "Winter Wyvern" },
  { 113, "npc_dota_hero_arc_warden", "Arc Warden" },
  { 114, "npc_dota_hero_monkey_king", "Monkey King" },
  { 119, "npc_dota_hero_dark_willow", "Dark Willow" },
  { 120, "npc_dota_hero_pangolier", "Pangolier" },
  { 121, "npc_dota_hero_grimstroke", "Grimstroke" },
  { 129, "npc_dota_hero_mars", "Mars" }
};