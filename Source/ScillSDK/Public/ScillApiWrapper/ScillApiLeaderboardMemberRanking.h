/**
 * SCILL API
 * SCILL gives you the tools to activate, retain and grow your user base in your app or game by bringing you features well known in the gaming industry: Gamification. We take care of the services and technology involved so you can focus on your game and content.
 *
 * OpenAPI spec version: 1.0.0
 * Contact: support@scillgame.com
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * https://github.com/OpenAPITools/openapi-generator
 * Do not edit the class manually.
 */

#pragma once

#include "ScillApiBaseModel.h"
#include "ScillApiWrapper/ScillApiLeaderboardRanking.h"

namespace ScillSDK
{

/*
 * ScillApiLeaderboardMemberRanking
 *
 * You get these object if you query the leaderboard ranking for a specific user. Only the requested user will be returned.
 */
class SCILLSDK_API ScillApiLeaderboardMemberRanking : public Model
{
public:
    virtual ~ScillApiLeaderboardMemberRanking() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	/* The id of the leaderboard */
	TOptional<FString> LeaderboardId;
	/* The name of the leaderboard */
	TOptional<FString> Name;
	TOptional<ScillApiLeaderboardRanking> Member;
};

}
