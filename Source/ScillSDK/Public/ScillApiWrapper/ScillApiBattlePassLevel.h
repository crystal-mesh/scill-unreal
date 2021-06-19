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

#include "ScillApiWrapper/ScillApiBaseModel.h"
#include "ScillApiWrapper/ScillApiBattlePassLevelChallenge.h"

namespace ScillSDK 
{

/*
 * ScillApiBattlePassLevel
 *
 * Battle Passes are grouped into levels that contain challenges that must be achieved to unlock the next level. Only challenges for the current level are tracking progress.
 */
class SCILLSDK_API ScillApiBattlePassLevel : public Model
{
public:
    virtual ~ScillApiBattlePassLevel() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	/* Unique id of this BattlePassLevel object. */
	TOptional<FString> LevelId;
	/* The app id */
	TOptional<FString> AppId;
	/* The id of the battle pass this level belongs to */
	TOptional<FString> BattlePassId;
	/* In the Admin Panel you can set different types of rewards. You can also set an identifier of an in-game-item or anything you like. Use this to include the reward into your own business logic. */
	TOptional<FString> RewardAmount;
	/* There are different types of rewards available. Possible values are Coins, Voucher, Money and Experience. This is deprecated in favor of level_reward_type which uses a slug instead of a human readable expression */
	TOptional<FString> RewardTypeName;
	/* The reward type in a machine readable slug. Available values are nothing, coin, experience, item */
	TOptional<FString> LevelRewardType;
	/* Indicates if this level is completed, i.e. all challenges have been completed. */
	TOptional<bool> LevelCompleted;
	/* Indicates the position of the level. */
	TOptional<double> LevelPriority;
	/* Indicates if this level has already be claimed. */
	TOptional<bool> RewardClaimed;
	/* The date when this level has been activated or null if it's not activated. */
	TOptional<FString> ActivatedAt;
	/* An array of BattlePassLevelChallenge objects. Please note, not all values are available from the challenge object, as battle passes handle the lifecycle of challenges. */
	TOptional<TArray<ScillApiBattlePassLevelChallenge>> Challenges;
};

}
