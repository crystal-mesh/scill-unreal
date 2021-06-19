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

#include "ScillApiWrapper/ScillApiEventsApi.h"

#include "ScillApiWrapper/ScillApiEventsApiOperations.h"
#include "ScillSDK.h"

#include "HttpModule.h"
#include "Serialization/JsonSerializer.h"

namespace ScillSDK 
{

ScillApiEventsApi::ScillApiEventsApi() 
: Url(TEXT("https://virtserver.swaggerhub.com/4Players-GmbH/scill-gaas/1.0.0"))
{
}

ScillApiEventsApi::~ScillApiEventsApi() {}

void ScillApiEventsApi::SetURL(const FString& InUrl)
{
	Url = InUrl;
}

void ScillApiEventsApi::AddHeaderParam(const FString& Key, const FString& Value)
{
	AdditionalHeaderParams.Add(Key, Value);
}

void ScillApiEventsApi::ClearHeaderParams()
{
	AdditionalHeaderParams.Reset();
}

bool ScillApiEventsApi::IsValid() const
{
	if (Url.IsEmpty())
	{
		UE_LOG(LogScillSDK, Error, TEXT("ScillApiEventsApi: Endpoint Url is not set, request cannot be performed"));
		return false;
	}

	return true;
}

void ScillApiEventsApi::SetHttpRetryManager(FHttpRetrySystem::FManager& InRetryManager)
{
	if(RetryManager != &GetHttpRetryManager())
	{
		DefaultRetryManager.Reset();
		RetryManager = &InRetryManager;
	}
}

FHttpRetrySystem::FManager& ScillApiEventsApi::GetHttpRetryManager()
{
	return *RetryManager;
}

FHttpRequestRef ScillApiEventsApi::CreateHttpRequest(const Request& Request) const
{
	if (!Request.GetRetryParams().IsSet())
	{
		return FHttpModule::Get().CreateRequest();
	}
	else
	{
		if (!RetryManager)
		{
			// Create default retry manager if none was specified
			DefaultRetryManager = MakeUnique<HttpRetryManager>(6, 60);
			RetryManager = DefaultRetryManager.Get();
		}

		const HttpRetryParams& Params = Request.GetRetryParams().GetValue();
		return RetryManager->CreateRequest(Params.RetryLimitCountOverride, Params.RetryTimeoutRelativeSecondsOverride, Params.RetryResponseCodes, Params.RetryVerbs, Params.RetryDomains);
	}
}

void ScillApiEventsApi::HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const
{
	InOutResponse.SetHttpResponse(HttpResponse);
	InOutResponse.SetSuccessful(bSucceeded);

	if (bSucceeded && HttpResponse.IsValid())
	{
		InOutResponse.SetHttpResponseCode((EHttpResponseCodes::Type)HttpResponse->GetResponseCode());
		FString ContentType = HttpResponse->GetContentType();
		FString Content;

		if (ContentType.IsEmpty())
		{
			return; // Nothing to parse
		}
		else if (ContentType.StartsWith(TEXT("application/json")) || ContentType.StartsWith("text/json"))
		{
			Content = HttpResponse->GetContentAsString();

			TSharedPtr<FJsonValue> JsonValue;
			auto Reader = TJsonReaderFactory<>::Create(Content);

			if (FJsonSerializer::Deserialize(Reader, JsonValue) && JsonValue.IsValid())
			{
				if (InOutResponse.FromJson(JsonValue))
					return; // Successfully parsed
			}
		}
		else if(ContentType.StartsWith(TEXT("text/plain")))
		{
			Content = HttpResponse->GetContentAsString();
			InOutResponse.SetResponseString(Content);
			return; // Successfully parsed
		}

		// Report the parse error but do not mark the request as unsuccessful. Data could be partial or malformed, but the request succeeded.
		UE_LOG(LogScillSDK, Error, TEXT("Failed to deserialize Http response content (type:%s):\n%s"), *ContentType , *Content);
		return;
	}

	// By default, assume we failed to establish connection
	InOutResponse.SetHttpResponseCode(EHttpResponseCodes::RequestTimeout);
}

bool ScillApiEventsApi::GetAvailableEvents(const GetAvailableEventsRequest& Request, const FGetAvailableEventsDelegate& Delegate /*= FGetAvailableEventsDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiEventsApi::OnGetAvailableEventsResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ScillApiEventsApi::OnGetAvailableEventsResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetAvailableEventsDelegate Delegate) const
{
	GetAvailableEventsResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

bool ScillApiEventsApi::SendEvent(const SendEventRequest& Request, const FSendEventDelegate& Delegate /*= FSendEventDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ScillApiEventsApi::OnSendEventResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ScillApiEventsApi::OnSendEventResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSendEventDelegate Delegate) const
{
	SendEventResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

}
