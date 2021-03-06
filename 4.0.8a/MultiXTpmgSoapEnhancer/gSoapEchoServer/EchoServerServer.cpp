/* EchoServerServer.cpp
   Generated by gSOAP 2.7.9l from EchoServer.h
   Copyright(C) 2000-2007, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/
#include "EchoServerH.h"

SOAP_SOURCE_STAMP("@(#) EchoServerServer.cpp ver 2.7.9l 2008-02-05 11:57:21 GMT")


SOAP_FMAC5 int SOAP_FMAC6 EchoServer_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif

	do
	{
#ifdef WITH_FASTCGI
		if (FCGI_Accept() < 0)
		{
			soap->error = SOAP_EOF;
			return soap_send_fault(soap);
		}
#endif

		soap_begin(soap);

#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif

		if (soap_begin_recv(soap))
		{	if (soap->error < SOAP_STOP)
			{
#ifdef WITH_FASTCGI
				soap_send_fault(soap);
#else 
				return soap_send_fault(soap);
#endif
			}
			soap_closesock(soap);

			continue;
		}

		if (soap_envelope_begin_in(soap)
		 || soap_recv_header(soap)
		 || soap_body_begin_in(soap)
		 || EchoServer_serve_request(soap)
		 || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 EchoServer_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "EchoServer:ToUpper"))
		return soap_serve_EchoServer__ToUpper(soap);
	if (!soap_match_tag(soap, soap->tag, "EchoServer:ToLower"))
		return soap_serve_EchoServer__ToLower(soap);
	if (!soap_match_tag(soap, soap->tag, "EchoServer:Echo"))
		return soap_serve_EchoServer__Echo(soap);
	if (!soap_match_tag(soap, soap->tag, "EchoServer:EchoWithSessionData"))
		return soap_serve_EchoServer__EchoWithSessionData(soap);
	if (!soap_match_tag(soap, soap->tag, "EchoServer:EchoWithApplicationData"))
		return soap_serve_EchoServer__EchoWithApplicationData(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__ToUpper(struct soap *soap)
{	struct EchoServer__ToUpper soap_tmp_EchoServer__ToUpper;
	struct EchoServer__ToUpperResponse soap_tmp_EchoServer__ToUpperResponse;
	soap_default_EchoServer__ToUpperResponse(soap, &soap_tmp_EchoServer__ToUpperResponse);
	soap_default_EchoServer__ToUpper(soap, &soap_tmp_EchoServer__ToUpper);
	soap->encodingStyle = NULL;
	if (!soap_get_EchoServer__ToUpper(soap, &soap_tmp_EchoServer__ToUpper, "EchoServer:ToUpper", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = EchoServer__ToUpper(soap, soap_tmp_EchoServer__ToUpper.S, soap_tmp_EchoServer__ToUpperResponse.Result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_EchoServer__ToUpperResponse(soap, &soap_tmp_EchoServer__ToUpperResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_EchoServer__ToUpperResponse(soap, &soap_tmp_EchoServer__ToUpperResponse, "EchoServer:ToUpperResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_EchoServer__ToUpperResponse(soap, &soap_tmp_EchoServer__ToUpperResponse, "EchoServer:ToUpperResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__ToLower(struct soap *soap)
{	struct EchoServer__ToLower soap_tmp_EchoServer__ToLower;
	struct EchoServer__ToLowerResponse soap_tmp_EchoServer__ToLowerResponse;
	soap_default_EchoServer__ToLowerResponse(soap, &soap_tmp_EchoServer__ToLowerResponse);
	soap_default_EchoServer__ToLower(soap, &soap_tmp_EchoServer__ToLower);
	soap->encodingStyle = NULL;
	if (!soap_get_EchoServer__ToLower(soap, &soap_tmp_EchoServer__ToLower, "EchoServer:ToLower", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = EchoServer__ToLower(soap, soap_tmp_EchoServer__ToLower.S, soap_tmp_EchoServer__ToLowerResponse.Result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_EchoServer__ToLowerResponse(soap, &soap_tmp_EchoServer__ToLowerResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_EchoServer__ToLowerResponse(soap, &soap_tmp_EchoServer__ToLowerResponse, "EchoServer:ToLowerResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_EchoServer__ToLowerResponse(soap, &soap_tmp_EchoServer__ToLowerResponse, "EchoServer:ToLowerResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__Echo(struct soap *soap)
{	struct EchoServer__Echo soap_tmp_EchoServer__Echo;
	struct EchoServer__EchoResponse soap_tmp_EchoServer__EchoResponse;
	soap_default_EchoServer__EchoResponse(soap, &soap_tmp_EchoServer__EchoResponse);
	soap_default_EchoServer__Echo(soap, &soap_tmp_EchoServer__Echo);
	soap->encodingStyle = NULL;
	if (!soap_get_EchoServer__Echo(soap, &soap_tmp_EchoServer__Echo, "EchoServer:Echo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = EchoServer__Echo(soap, soap_tmp_EchoServer__Echo.S, soap_tmp_EchoServer__EchoResponse.Result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_EchoServer__EchoResponse(soap, &soap_tmp_EchoServer__EchoResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_EchoServer__EchoResponse(soap, &soap_tmp_EchoServer__EchoResponse, "EchoServer:EchoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_EchoServer__EchoResponse(soap, &soap_tmp_EchoServer__EchoResponse, "EchoServer:EchoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__EchoWithSessionData(struct soap *soap)
{	struct EchoServer__EchoWithSessionData soap_tmp_EchoServer__EchoWithSessionData;
	struct EchoServer__EchoWithSessionDataResponse soap_tmp_EchoServer__EchoWithSessionDataResponse;
	soap_default_EchoServer__EchoWithSessionDataResponse(soap, &soap_tmp_EchoServer__EchoWithSessionDataResponse);
	soap_default_EchoServer__EchoWithSessionData(soap, &soap_tmp_EchoServer__EchoWithSessionData);
	soap->encodingStyle = NULL;
	if (!soap_get_EchoServer__EchoWithSessionData(soap, &soap_tmp_EchoServer__EchoWithSessionData, "EchoServer:EchoWithSessionData", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = EchoServer__EchoWithSessionData(soap, soap_tmp_EchoServer__EchoWithSessionData.S, soap_tmp_EchoServer__EchoWithSessionDataResponse.Result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_EchoServer__EchoWithSessionDataResponse(soap, &soap_tmp_EchoServer__EchoWithSessionDataResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_EchoServer__EchoWithSessionDataResponse(soap, &soap_tmp_EchoServer__EchoWithSessionDataResponse, "EchoServer:EchoWithSessionDataResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_EchoServer__EchoWithSessionDataResponse(soap, &soap_tmp_EchoServer__EchoWithSessionDataResponse, "EchoServer:EchoWithSessionDataResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__EchoWithApplicationData(struct soap *soap)
{	struct EchoServer__EchoWithApplicationData soap_tmp_EchoServer__EchoWithApplicationData;
	struct EchoServer__EchoWithApplicationDataResponse soap_tmp_EchoServer__EchoWithApplicationDataResponse;
	soap_default_EchoServer__EchoWithApplicationDataResponse(soap, &soap_tmp_EchoServer__EchoWithApplicationDataResponse);
	soap_default_EchoServer__EchoWithApplicationData(soap, &soap_tmp_EchoServer__EchoWithApplicationData);
	soap->encodingStyle = NULL;
	if (!soap_get_EchoServer__EchoWithApplicationData(soap, &soap_tmp_EchoServer__EchoWithApplicationData, "EchoServer:EchoWithApplicationData", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = EchoServer__EchoWithApplicationData(soap, soap_tmp_EchoServer__EchoWithApplicationData.S, soap_tmp_EchoServer__EchoWithApplicationDataResponse.Result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_EchoServer__EchoWithApplicationDataResponse(soap, &soap_tmp_EchoServer__EchoWithApplicationDataResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_EchoServer__EchoWithApplicationDataResponse(soap, &soap_tmp_EchoServer__EchoWithApplicationDataResponse, "EchoServer:EchoWithApplicationDataResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_EchoServer__EchoWithApplicationDataResponse(soap, &soap_tmp_EchoServer__EchoWithApplicationDataResponse, "EchoServer:EchoWithApplicationDataResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

/* End of EchoServerServer.cpp */
