#include "User.h"
#include "static.h"
#include "cpprest\http_client.h"

using namespace std;
using namespace web::json;
using namespace utility;
using namespace web::http;
using namespace web::http::client;

DiscordCPP::User::User() {
	//_log = Logger("discord.user");
	//_log.debug("created empty user object");
}

DiscordCPP::User::User(value data, string_t token) : DiscordCPP::DiscordObject(token) {
	//_log = Logger("discord.user");

	//_log.debug(conversions::to_utf8string(data.serialize()));

	if (is_valid_field("id"))
		id = conversions::to_utf8string(data.at(U("id")).as_string());
	
	if (is_valid_field("username"))
		username = conversions::to_utf8string(data.at(U("username")).as_string());
	
	if (is_valid_field("discrimminator"))
		discriminator = conversions::to_utf8string(data.at(U("discriminator")).as_string());
	
	if (is_valid_field("avatar"))
		avatar = conversions::to_utf8string(data.at(U("avatar")).as_string());

	if (is_valid_field("bot"))
		bot = data.at(U("bot")).as_bool();

	if (is_valid_field("mfa_enabled"))
		mfa_enabled = data.at(U("mfa_enabled")).as_bool();
	
	if (is_valid_field("verified"))
		verified = data.at(U("verified")).as_bool();

	if (is_valid_field("email"))
		email = conversions::to_utf8string(data.at(U("email")).as_string());

	//_log.debug("created user object");
}

DiscordCPP::User::User(string id, string_t token) : DiscordCPP::DiscordObject(token) {
	//_log = Logger("discord.user");

	string url = "/users/" + id;

	*this = User(api_call(url), token);
}

DiscordCPP::User::~User() {
	//_log.debug("destroyed user object");
}
