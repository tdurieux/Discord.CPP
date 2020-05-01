#pragma once
#include <iostream>
#include <cpprest/json.h>
#include <cpprest/http_client.h>

namespace DiscordCPP {

	class DiscordObject {
	protected:
		///token to authentificate with the discord api
		utility::string_t _token;

		///helper function to communicate with the http api
		web::json::value api_call(const std::string& url, const web::http::method& method = web::http::methods::GET, const web::json::value& data = web::json::value(), const std::string& content_type = "", const bool cache = true);
	public:
		///the id of the object
		std::string id;	//snowflake

		DiscordObject();
		DiscordObject(const utility::string_t& token);
	};

}
