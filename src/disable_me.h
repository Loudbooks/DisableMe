//
// Created by Loudbook on 9/30/24.
//

#pragma once

#include <algorithm>
#include <endstone/plugin/plugin.h>
#include <endstone/event/player/player_join_event.h>
#include <endstone/event/player/player_command_event.h>

class DisableMe : public endstone::Plugin {
public:
    void onEnable() override {
        registerEvent(&DisableMe::onPlayerCommand, *this);
        registerEvent(&DisableMe::onPlayerJoin, *this);
    }

    void onPlayerJoin(const endstone::PlayerJoinEvent& event) {
        event.getPlayer().addAttachment(*this, "minecraft.command.me", false);
    }

    void onPlayerCommand(endstone::PlayerCommandEvent& event) {
        std::string command = event.getCommand();

        if (const std::ptrdiff_t at_count = std::count(command.begin(), command.end(), '@'); at_count < 5) return;

        event.setCancelled(true);
        event.getPlayer().sendMessage("Invalid command.");
    }
};
