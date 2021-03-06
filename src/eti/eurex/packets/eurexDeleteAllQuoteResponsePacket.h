/*
 * Copyright 2014-2018 Neueda Ltd.
 * 
 * Generated 21/05/2019
 */
#ifndef EUREX_DELETEALLQUOTERESPONSE_PACKET_H
#define EUREX_DELETEALLQUOTERESPONSE_PACKET_H

#include <string>
#include <vector>
#include <sstream>
#include <cstddef>
#include <stdint.h>
#include "eurexPackets.h"
#include "EtiPacketUtils.h"

namespace neueda
{

using namespace std;

class eurexDeleteAllQuoteResponsePacket
{
    public:
        // no value constants
        static const uint64_t MASS_ACTION_REPORT_ID_MIN;
        static const uint64_t MASS_ACTION_REPORT_ID_MAX;
        static const uint64_t MASS_ACTION_REPORT_ID_NO_VALUE;
        static const int16_t NO_NOT_AFFECTED_SECURITIES_MIN;
        static const int16_t NO_NOT_AFFECTED_SECURITIES_MAX;
        static const int16_t NO_NOT_AFFECTED_SECURITIES_NO_VALUE;
        static const char PAD6_NO_VALUE[6];
        static const size_t PAD6_MAX_LENGTH;
        static const size_t NOT_AFFECTED_SECURITIES_GRP_MIN;
        static const size_t NOT_AFFECTED_SECURITIES_GRP_MAX;

        // fields (use with care)
        eurexMessageHeaderOutCompPacket mMessageHeaderOut;
        eurexNRResponseHeaderMECompPacket mNRResponseHeaderME;
        uint64_t mMassActionReportID;
        int16_t mNoNotAffectedSecurities;
        char mPad6[6];
        vector<eurexNotAffectedSecuritiesGrpCompPacket> mNotAffectedSecuritiesGrp;

        // constructor
        eurexDeleteAllQuoteResponsePacket ()
        {
            mMessageHeaderOut.mTemplateID = 10409;
            mMassActionReportID = MASS_ACTION_REPORT_ID_NO_VALUE;
            mNoNotAffectedSecurities = NO_NOT_AFFECTED_SECURITIES_NO_VALUE;
            memcpy(mPad6, PAD6_NO_VALUE, sizeof (mPad6));
        }

        // getters & setters
        const eurexMessageHeaderOutCompPacket& getMessageHeaderOut () const
        {
            return mMessageHeaderOut;
        }

        bool setMessageHeaderOut (const eurexMessageHeaderOutCompPacket& v)
        {
            mMessageHeaderOut = v;
            return true;
        }

        const eurexNRResponseHeaderMECompPacket& getNRResponseHeaderME () const
        {
            return mNRResponseHeaderME;
        }

        bool setNRResponseHeaderME (const eurexNRResponseHeaderMECompPacket& v)
        {
            mNRResponseHeaderME = v;
            return true;
        }

        uint64_t getMassActionReportID () const
        {
            return mMassActionReportID;
        }

        bool setMassActionReportID (uint64_t v)
        {
            mMassActionReportID = v;
            return ((MASS_ACTION_REPORT_ID_MIN <= mMassActionReportID && mMassActionReportID <= MASS_ACTION_REPORT_ID_MAX) || mMassActionReportID == MASS_ACTION_REPORT_ID_NO_VALUE);
        }

        bool isMassActionReportIDValid () const
        {
            return (mMassActionReportID != MASS_ACTION_REPORT_ID_NO_VALUE);
        }

        void resetMassActionReportID ()
        {
            mMassActionReportID = MASS_ACTION_REPORT_ID_NO_VALUE;
        }

        int16_t getNoNotAffectedSecurities () const
        {
            return mNoNotAffectedSecurities;
        }

        bool setNoNotAffectedSecurities (int16_t v)
        {
            mNoNotAffectedSecurities = v;
            return ((NO_NOT_AFFECTED_SECURITIES_MIN <= mNoNotAffectedSecurities && mNoNotAffectedSecurities <= NO_NOT_AFFECTED_SECURITIES_MAX) || mNoNotAffectedSecurities == NO_NOT_AFFECTED_SECURITIES_NO_VALUE);
        }

        bool isNoNotAffectedSecuritiesValid () const
        {
            return (mNoNotAffectedSecurities != NO_NOT_AFFECTED_SECURITIES_NO_VALUE);
        }

        void resetNoNotAffectedSecurities ()
        {
            mNoNotAffectedSecurities = NO_NOT_AFFECTED_SECURITIES_NO_VALUE;
        }

        string getPad6 () const
        {
            return string (mPad6, PAD6_MAX_LENGTH);
        }

        bool setPad6 (const string& v)
        {
            memset (mPad6, '\0', sizeof (mPad6));
            size_t size = min ((size_t) v.size (), (size_t) PAD6_MAX_LENGTH);
            strncpy (mPad6, v.c_str (), size);
            return (v.size () <= PAD6_MAX_LENGTH);
        }

        bool isPad6Valid () const
        {
            return (memcmp (mPad6, PAD6_NO_VALUE, sizeof (mPad6)) != 0);
        }

        void resetPad6 ()
        {
            memcpy (mPad6, PAD6_NO_VALUE, sizeof (mPad6));
        }

        const vector<eurexNotAffectedSecuritiesGrpCompPacket>& getNotAffectedSecuritiesGrp () const
        {
            return mNotAffectedSecuritiesGrp;
        }

        bool setNotAffectedSecuritiesGrp (const vector<eurexNotAffectedSecuritiesGrpCompPacket>& v)
        {
            mNotAffectedSecuritiesGrp = v;
            mNoNotAffectedSecurities = v.size ();
            return (NOT_AFFECTED_SECURITIES_GRP_MIN <= v.size () && v.size () <= NOT_AFFECTED_SECURITIES_GRP_MAX);
        }


        // render current raw size
        size_t getRawSize () const
        {
            size_t result = mMessageHeaderOut.getRawSize()
                + mNRResponseHeaderME.getRawSize()
                + sizeof (mMassActionReportID)
                + sizeof (mNoNotAffectedSecurities)
                + sizeof (mPad6)
                + eti::getRawSize (mNotAffectedSecuritiesGrp);
            return result;
        }

        // serialization
        codecState serialize (void *buf, size_t len, size_t &used)
        {
            mNoNotAffectedSecurities = mNotAffectedSecuritiesGrp.size ();
            mMessageHeaderOut.mBodyLen = getRawSize ();
            codecState state;
            state = mMessageHeaderOut.serialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = mNRResponseHeaderME.serialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::serialize (mMassActionReportID, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::serialize (mNoNotAffectedSecurities, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::serialize (mPad6, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            for (size_t i = 0; i < mNotAffectedSecuritiesGrp.size (); i++)
            {
                state = mNotAffectedSecuritiesGrp[i].serialize (buf, len, used);
                if (state != GW_CODEC_SUCCESS) return state;
            }
            return GW_CODEC_SUCCESS;
        }

        // deserialization
        codecState deserialize (const void *buf, size_t len, size_t &used)
        {
            codecState state;
            state = mMessageHeaderOut.deserialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = mNRResponseHeaderME.deserialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::deserialize (mMassActionReportID, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::deserialize (mNoNotAffectedSecurities, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::deserialize (mPad6, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            mNotAffectedSecuritiesGrp.resize (mNoNotAffectedSecurities);
            for (vector<eurexNotAffectedSecuritiesGrpCompPacket>::iterator it = mNotAffectedSecuritiesGrp.begin (); it != mNotAffectedSecuritiesGrp.end (); ++it)
            {
                state = it->deserialize (buf, len, used);
                if (state != GW_CODEC_SUCCESS) return state;
            }
            mMessageHeaderOut.mBodyLen = getRawSize ();
            return GW_CODEC_SUCCESS;
        }

        // string conversion
        string toString () const
        {
            stringstream sss;
            sss << "DeleteAllQuoteResponse::"
                << "[MessageHeaderOut=" << mMessageHeaderOut.toString () << "],"
                << "[NRResponseHeaderME=" << mNRResponseHeaderME.toString () << "],"
                << "[MassActionReportID=" << getMassActionReportID () << "],"
                << "[NoNotAffectedSecurities=" << getNoNotAffectedSecurities () << "],"
                << "[Pad6=" << getPad6 () << "],"
                << "[NotAffectedSecuritiesGrp=" << eti::toString (getNotAffectedSecuritiesGrp ()) << "]";
            return sss.str();
        }
};

const uint64_t eurexDeleteAllQuoteResponsePacket::MASS_ACTION_REPORT_ID_MIN = 0UL;
const uint64_t eurexDeleteAllQuoteResponsePacket::MASS_ACTION_REPORT_ID_MAX = 18446744073709551614UL;
const uint64_t eurexDeleteAllQuoteResponsePacket::MASS_ACTION_REPORT_ID_NO_VALUE = 0xFFFFFFFFFFFFFFFF;
const int16_t eurexDeleteAllQuoteResponsePacket::NO_NOT_AFFECTED_SECURITIES_MIN = 0;
const int16_t eurexDeleteAllQuoteResponsePacket::NO_NOT_AFFECTED_SECURITIES_MAX = 500;
const int16_t eurexDeleteAllQuoteResponsePacket::NO_NOT_AFFECTED_SECURITIES_NO_VALUE = 0xFFFF;
const char eurexDeleteAllQuoteResponsePacket::PAD6_NO_VALUE[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const size_t eurexDeleteAllQuoteResponsePacket::PAD6_MAX_LENGTH = 6;
const size_t eurexDeleteAllQuoteResponsePacket::NOT_AFFECTED_SECURITIES_GRP_MIN = 0;
const size_t eurexDeleteAllQuoteResponsePacket::NOT_AFFECTED_SECURITIES_GRP_MAX = 500;


} // namespace neueda

#endif // EUREX_DELETEALLQUOTERESPONSE_PACKET_H
