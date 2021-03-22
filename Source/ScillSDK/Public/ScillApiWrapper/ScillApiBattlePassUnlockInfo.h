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

namespace ScillSDK 
{

/*
 * ScillApiBattlePassUnlockInfo
 *
 * 
 */
class SCILLSDK_API ScillApiBattlePassUnlockInfo : public Model
{
public:
    virtual ~ScillApiBattlePassUnlockInfo() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	/* The id of this battle pass purchase */
	TOptional<FString> PurchaseId;
	/* The battle pass id */
	TOptional<FString> BattlePassId;
	/* The user id of this battle pass purchase */
	TOptional<FString> UserId;
	/* The price paid for this battle pass */
	TOptional<double> PurchasePrice;
	/* The currency used to purchase this battle pass */
	TOptional<FString> PurchaseCurrency;
	/* The date this battle pass has been purchased */
	TOptional<FString> PurchasedAt;
	/* Indicates if this battle pass has been completed */
	TOptional<bool> BattlePassCompleted;
};

}
