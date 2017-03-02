// FieldIDs
#define PNRP_HEADER 0x0010
#define PNRP_HEADER_ACKED 0x0018
#define PNRP_ID 0x0030
#define TARGET_PNRP_ID 0x0038
#define VALIDATE_PNRP_ID 0x0039
#define FLAGS_FIELD 0x0040
#define FLOOD_CONTROLS 0x0043
#define SOLICIT_CONTROLS 0x0044
#define LOOKUP_CONTROLS 0x0045
#define EXTENDED_PAYLOAD 0x005A
#define PNRP_ID_ARRAY 0x0060
#define CERT_CHAIN 0x0080
#define WCHAR 0x084
#define CLASSIFIER 0x0085
#define HASHED_NONCE 0x0092
#define NONCE 0x0093
#define SPLIT_CONTROLS 0x0098
#define ROUTING_ENTRY 0x009A
#define VALIDATE_CPA 0x009B
#define REVOKE_CPA 0x009D
#define IPV6_ENDPOINT_ARRAY 0x009E

// Messages
struct message_header {
	unsigned short field_id,
	unsigned short length
};

struct advertise_message {
	unsigned int acked_message_id,
	unsigned short num_entries
	// TODO
}