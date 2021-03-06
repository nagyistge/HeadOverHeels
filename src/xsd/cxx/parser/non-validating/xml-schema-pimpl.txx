// file      : xsd/cxx/parser/non-validating/xml-schema-pimpl.txx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2007 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <limits>
#include <xsd/cxx/zc-istream.hxx>

namespace xsd
{
  namespace cxx
  {
    namespace parser
    {
      namespace non_validating
      {
        // Note that most of the types implemented here cannot have
        // whitespaces in the value. As result we don't need to waste
        // time collapsing whitespaces. All we need to do is trim the
        // string representation which can be done without copying.
        //

        // any_type
        //

        template <typename C>
        void any_type_pimpl<C>::
        post_any_type ()
        {
        }

        // any_simple_type
        //

        template <typename C>
        void any_simple_type_pimpl<C>::
        post_any_simple_type ()
        {
        }

        // boolean
        //
        template <typename C>
        void boolean_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void boolean_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        bool boolean_pimpl<C>::
        post_boolean ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          return str == bits::true_<C> () || str == bits::one<C> ();
        }

        // byte
        //

        template <typename C>
        void byte_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void byte_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        signed char byte_pimpl<C>::
        post_byte ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          short t;
          zc_istream<C> is (str);
          is >> t;

          return static_cast<signed char> (t);
        }

        // unsigned_byte
        //

        template <typename C>
        void unsigned_byte_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void unsigned_byte_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        unsigned char unsigned_byte_pimpl<C>::
        post_unsigned_byte ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          unsigned short t;
          zc_istream<C> is (str);
          is >> t;

          return static_cast<unsigned char> (t);
        }

        // short
        //

        template <typename C>
        void short_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void short_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        short short_pimpl<C>::
        post_short ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          short t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // unsigned_short
        //

        template <typename C>
        void unsigned_short_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void unsigned_short_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        unsigned short unsigned_short_pimpl<C>::
        post_unsigned_short ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          unsigned short t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // int
        //

        template <typename C>
        void int_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void int_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        int int_pimpl<C>::
        post_int ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          int t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // unsigned_int
        //

        template <typename C>
        void unsigned_int_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void unsigned_int_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        unsigned int unsigned_int_pimpl<C>::
        post_unsigned_int ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          unsigned int t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // long
        //
        template <typename C>
        void long_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void long_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        long long long_pimpl<C>::
        post_long ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          long long t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // unsigned_long
        //
        template <typename C>
        void unsigned_long_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void unsigned_long_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        unsigned long long unsigned_long_pimpl<C>::
        post_unsigned_long ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          unsigned long long t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // integer
        //
        template <typename C>
        void integer_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void integer_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        long long integer_pimpl<C>::
        post_integer ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          long long t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // negative_integer
        //
        template <typename C>
        void negative_integer_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void negative_integer_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        long long negative_integer_pimpl<C>::
        post_negative_integer ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          long long t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // non_positive_integer
        //
        template <typename C>
        void non_positive_integer_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void non_positive_integer_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        long long non_positive_integer_pimpl<C>::
        post_non_positive_integer ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          long long t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // positive_integer
        //
        template <typename C>
        void positive_integer_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void positive_integer_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        unsigned long long positive_integer_pimpl<C>::
        post_positive_integer ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          unsigned long long t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // non_negative_integer
        //
        template <typename C>
        void non_negative_integer_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void non_negative_integer_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        unsigned long long non_negative_integer_pimpl<C>::
        post_non_negative_integer ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          unsigned long long t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // float
        //
        template <typename C>
        void float_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void float_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        float float_pimpl<C>::
        post_float ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          if (str == bits::positive_inf<C> ())
            return std::numeric_limits<float>::infinity ();

          if (str == bits::negative_inf<C> ())
            return -std::numeric_limits<float>::infinity ();

          if (str == bits::nan<C> ())
            return std::numeric_limits<float>::quiet_NaN ();

          float t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // double
        //
        template <typename C>
        void double_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void double_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        double double_pimpl<C>::
        post_double ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          if (str == bits::positive_inf<C> ())
            return std::numeric_limits<double>::infinity ();

          if (str == bits::negative_inf<C> ())
            return -std::numeric_limits<double>::infinity ();

          if (str == bits::nan<C> ())
            return std::numeric_limits<double>::quiet_NaN ();

          double t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }

        // decimal
        //
        template <typename C>
        void decimal_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void decimal_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        double decimal_pimpl<C>::
        post_decimal ()
        {
          std::basic_string<C> tmp;
          tmp.swap (str_);

          ro_string<C> str (tmp);
          trim (str);

          double t;
          zc_istream<C> is (str);
          is >> t;

          return t;
        }


        // string
        //
        template <typename C>
        void string_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void string_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        std::basic_string<C> string_pimpl<C>::
        post_string ()
        {
          std::basic_string<C> r;
          r.swap (str_);
          return r;
        }

        // normalized_string
        //
        template <typename C>
        void normalized_string_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void normalized_string_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          str_ += s;
        }

        template <typename C>
        std::basic_string<C> normalized_string_pimpl<C>::
        post_normalized_string ()
        {
          typedef typename std::basic_string<C>::size_type size_type;

          size_type size (str_.size ());

          for (size_type i (0); i < size; ++i)
          {
            C& c = str_[i];

            if (c == C (0x0A) || c == C (0x0D) || c == C (0x09))
              c = C (0x20);
          }

          std::basic_string<C> r;
          r.swap (str_);
          return r;
        }

        // token
        //
        template <typename C>
        void token_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void token_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        std::basic_string<C> token_pimpl<C>::
        post_token ()
        {
          typedef typename std::basic_string<C>::size_type size_type;

          size_type size (str_.size ());
          size_type j (0);

          bool subs (false);

          for (size_type i (0); i < size; ++i)
          {
            C c = str_[i];

            if (c == C (0x20) || c == C (0x0A) ||
                c == C (0x0D) || c == C (0x09))
            {
              subs = true;
            }
            else
            {
              if (subs)
              {
                subs = false;
                str_[j++] = C (0x20);
              }

              str_[j++] = c;
            }
          }

          str_.resize (j);

          std::basic_string<C> r;
          r.swap (str_);
          return r;
        }

        // name
        //
        template <typename C>
        void name_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void name_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        std::basic_string<C> name_pimpl<C>::
        post_name ()
        {
          ro_string<C> tmp (str_);
          str_.resize (trim_right (tmp));

          std::basic_string<C> r;
          r.swap (str_);
          return r;
        }

        // nmtoken
        //
        template <typename C>
        void nmtoken_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void nmtoken_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        std::basic_string<C> nmtoken_pimpl<C>::
        post_nmtoken ()
        {
          ro_string<C> tmp (str_);
          str_.resize (trim_right (tmp));

          std::basic_string<C> r;
          r.swap (str_);
          return r;
        }

        // nmtokens
        //
        template <typename C>
        void nmtokens_pimpl<C>::
        _pre ()
        {
          seq_.clear ();
        }

        template <typename C>
        string_sequence<C> nmtokens_pimpl<C>::
        post_nmtokens ()
        {
          string_sequence<C> r;
          r.swap (seq_);
          return r;
        }

        template <typename C>
        void nmtokens_pimpl<C>::
        _xsd_parse_item (const ro_string<C>& s)
        {
          parser_.pre ();
          parser_._pre ();
          parser_._characters (s);
          parser_._post ();
          seq_.push_back (parser_.post_nmtoken ());
        }

        // ncname
        //
        template <typename C>
        void ncname_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void ncname_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        std::basic_string<C> ncname_pimpl<C>::
        post_ncname ()
        {
          ro_string<C> tmp (str_);
          str_.resize (trim_right (tmp));

          std::basic_string<C> r;
          r.swap (str_);
          return r;
        }

        // id
        //
        template <typename C>
        std::basic_string<C> id_pimpl<C>::
        post_id ()
        {
          return this->post_ncname ();
        }

        // idref
        //
        template <typename C>
        std::basic_string<C> idref_pimpl<C>::
        post_idref ()
        {
          return this->post_ncname ();
        }

        // idrefs
        //
        template <typename C>
        void idrefs_pimpl<C>::
        _pre ()
        {
          seq_.clear ();
        }

        template <typename C>
        string_sequence<C> idrefs_pimpl<C>::
        post_idrefs ()
        {
          string_sequence<C> r;
          r.swap (seq_);
          return r;
        }

        template <typename C>
        void idrefs_pimpl<C>::
        _xsd_parse_item (const ro_string<C>& s)
        {
          parser_.pre ();
          parser_._pre ();
          parser_._characters (s);
          parser_._post ();
          seq_.push_back (parser_.post_idref ());
        }

        // language
        //
        template <typename C>
        void language_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void language_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        std::basic_string<C> language_pimpl<C>::
        post_language ()
        {
          ro_string<C> tmp (str_);
          str_.resize (trim_right (tmp));

          std::basic_string<C> r;
          r.swap (str_);
          return r;
        }

        // uri
        //
        template <typename C>
        void uri_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void uri_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        std::basic_string<C> uri_pimpl<C>::
        post_uri ()
        {
          ro_string<C> tmp (str_);
          str_.resize (trim_right (tmp));

          std::basic_string<C> r;
          r.swap (str_);
          return r;
        }

        // qname
        //
        template <typename C>
        void qname_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void qname_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        qname<C> qname_pimpl<C>::
        post_qname ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));
          size_type pos (tmp.find (C (':')));

          if (pos != ro_string<C>::npos)
          {
            std::basic_string<C> prefix (tmp.data (), pos++);
            std::basic_string<C> name (tmp.data () + pos, size - pos);
            return qname<C> (prefix, name);
          }
          else
          {
            str_.resize (size);
            return qname<C> (str_);
          }
        }

        // base64_binary
        //
        template <typename C>
        void base64_binary_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void base64_binary_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        namespace bits
        {
          template <typename C>
          inline unsigned char
          base64_decode (C c)
          {
            unsigned char r (0xFF);

            if (c >= C('A') && c <= C ('Z'))
              r = static_cast<unsigned char> (c - C ('A'));
            else if (c >= C('a') && c <= C ('z'))
              r = static_cast<unsigned char> (c - C ('a') + 26);
            else if (c >= C('0') && c <= C ('9'))
              r = static_cast<unsigned char> (c - C ('0') + 52);
            else if (c == C ('+'))
              r = 62;
            else if (c == C ('/'))
              r = 63;

            return r;
          }
        }

        template <typename C>
        std::auto_ptr<buffer> base64_binary_pimpl<C>::
        post_base64_binary ()
        {
          typedef typename std::basic_string<C>::size_type size_type;

          size_type size (str_.size ());
          const C* src (str_.c_str ());

          // Remove all whitespaces.
          //
          {
            size_type j (0);

            bool subs (false);

            for (size_type i (0); i < size; ++i)
            {
              C c = str_[i];

              if (c == C (0x20) || c == C (0x0A) ||
                  c == C (0x0D) || c == C (0x09))
              {
                subs = true;
              }
              else
              {
                if (subs)
                  subs = false;

                str_[j++] = c;
              }
            }

            size = j;
            str_.resize (size);
          }

          // Our length should be a multiple of four.
          //
          size_type quad_count (size / 4);
          size_type capacity (quad_count * 3 + 1);

          std::auto_ptr<buffer> buf (new buffer (capacity, capacity));
          char* dst (buf->data ());

          size_type si (0), di (0); // Source and destination indexes.

          // Process all quads except the last one.
          //
          unsigned char b1, b2, b3, b4;

          for (size_type q (0); q < quad_count - 1; ++q)
          {
            b1 = bits::base64_decode (src[si++]);
            b2 = bits::base64_decode (src[si++]);
            b3 = bits::base64_decode (src[si++]);
            b4 = bits::base64_decode (src[si++]);

            dst[di++] = (b1 << 2) | (b2 >> 4);
            dst[di++] = (b2 << 4) | (b3 >> 2);
            dst[di++] = (b3 << 6) | b4;
          }

          // Process the last quad. The first two octets are always there.
          //
          b1 = bits::base64_decode (src[si++]);
          b2 = bits::base64_decode (src[si++]);

          C e3 (src[si++]);
          C e4 (src[si++]);

          if (e4 == C ('='))
          {
            if (e3 == C ('='))
            {
              // Two pads. Last 4 bits in b2 should be zero.
              //
              dst[di++] = (b1 << 2) | (b2 >> 4);
            }
            else
            {
              // One pad. Last 2 bits in b3 should be zero.
              //
              b3 = bits::base64_decode (e3);

              dst[di++] = (b1 << 2) | (b2 >> 4);
              dst[di++] = (b2 << 4) | (b3 >> 2);
            }
          }
          else
          {
            // No pads.
            //
            b3 = bits::base64_decode (e3);
            b4 = bits::base64_decode (e4);

            dst[di++] = (b1 << 2) | (b2 >> 4);
            dst[di++] = (b2 << 4) | (b3 >> 2);
            dst[di++] = (b3 << 6) | b4;
          }

          // Set the real size.
          //
          buf->size (di);

          return buf;
        }

        // hex_binary
        //
        template <typename C>
        void hex_binary_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void hex_binary_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        namespace bits
        {
          template <typename C>
          inline unsigned char
          hex_decode (C c)
          {
            unsigned char r (0xFF);

            if (c >= C('0') && c <= C ('9'))
              r = static_cast<unsigned char> (c - C ('0'));
            else if (c >= C ('A') && c <= C ('F'))
              r = static_cast<unsigned char> (10 + (c - C ('A')));
            else if (c >= C ('a') && c <= C ('f'))
              r = static_cast<unsigned char> (10 + (c - C ('a')));

            return r;
          }
        }

        template <typename C>
        std::auto_ptr<buffer> hex_binary_pimpl<C>::
        post_hex_binary ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          buffer::size_t n (size / 2);
          std::auto_ptr<buffer> buf (new buffer (n));

          const C* src (tmp.data ());
          char* dst (buf->data ());

          for (buffer::size_t i (0); i < n; ++i)
          {
            unsigned char h (bits::hex_decode (src[2 * i]));
            unsigned char l (bits::hex_decode (src[2 * i + 1]));
            dst[i] = (h << 4) | l;
          }

          return buf;
        }

        // gday
        //
        template <typename C>
        void gday_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void gday_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        gday<C> gday_pimpl<C>::
        post_gday ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          unsigned short day (0);
          std::basic_string<C> zone;

          // gday := ---DD[Z|(+|-)HH::MM]
          //
          if (size >= 5)
          {
            ro_string<C> day_fragment (tmp.data () + 3, 2);
            zc_istream<C> is (day_fragment);
            is >> day;

            if (size > 5)
              zone.assign (tmp.data () + 5, size - 5);
          }

          return zone.empty () ? gday<C> (day) : gday<C> (day, zone);
        }

        // gmonth
        //
        template <typename C>
        void gmonth_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void gmonth_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        gmonth<C> gmonth_pimpl<C>::
        post_gmonth ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          unsigned short month (0);
          std::basic_string<C> zone;

          // gmonth := --MM[Z|(+|-)HH::MM]
          //
          if (size >= 4)
          {
            ro_string<C> month_fragment (tmp.data () + 2, 2);
            zc_istream<C> is (month_fragment);
            is >> month;

            if (size > 4)
              zone.assign (tmp.data () + 4, size - 4);
          }

          return zone.empty () ? gmonth<C> (month) : gmonth<C> (month, zone);
        }

        // gyear
        //
        template <typename C>
        void gyear_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void gyear_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        gyear<C> gyear_pimpl<C>::
        post_gyear ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          int year (0);
          std::basic_string<C> zone;

          // gyear := [-]CCYY[N]*[Z|(+|-)HH::MM]
          //

          if (size >= 4)
          {
            // Find the end of the year token.
            //
            size_type pos (4);
            for (; pos < size; ++pos)
            {
              C c (tmp[pos]);

              if (c == C ('Z') || c == C ('+') || c == C ('-'))
                break;
            }

            ro_string<C> year_fragment (tmp.data (), pos);
            zc_istream<C> is (year_fragment);
            is >> year;

            if (pos < size)
              zone.assign (tmp.data () + pos, size - pos);
          }

          return zone.empty () ? gyear<C> (year) : gyear<C> (year, zone);
        }

        // gmonth_day
        //
        template <typename C>
        void gmonth_day_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void gmonth_day_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        gmonth_day<C> gmonth_day_pimpl<C>::
        post_gmonth_day ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          unsigned short month (0), day (0);
          std::basic_string<C> zone;

          // gmonth_day := --MM-DD[Z|(+|-)HH::MM]
          //
          if (size >= 7)
          {
            ro_string<C> month_fragment (tmp.data () + 2, 2);
            zc_istream<C> mis (month_fragment);
            mis >> month;

            ro_string<C> day_fragment (tmp.data () + 5, 2);
            zc_istream<C> dis (day_fragment);
            dis >> day;

            if (size > 7)
              zone.assign (tmp.data () + 7, size - 7);
          }

          return zone.empty ()
            ? gmonth_day<C> (month, day)
            : gmonth_day<C> (month, day, zone);
        }

        // gyear_month
        //
        template <typename C>
        void gyear_month_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void gyear_month_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        gyear_month<C> gyear_month_pimpl<C>::
        post_gyear_month ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          int year (0);
          unsigned short month (0);
          std::basic_string<C> zone;

          // gyear_month := [-]CCYY[N]*-MM[Z|(+|-)HH::MM]
          //

          if (size >= 7)
          {
            // Find the end of the year token.
            //
            size_type pos (tmp.find (C ('-'), 4));

            if (pos != ro_string<C>::npos && (size - pos - 1) >= 2)
            {
              ro_string<C> year_fragment (tmp.data (), pos);
              zc_istream<C> yis (year_fragment);
              yis >> year;

              ro_string<C> month_fragment (tmp.data () + pos + 1, 2);
              zc_istream<C> mis (month_fragment);
              mis >> month;

              pos += 3;

              if (pos < size)
                zone.assign (tmp.data () + pos, size - pos);
            }
          }

          return zone.empty ()
            ? gyear_month<C> (year, month)
            : gyear_month<C> (year, month, zone);
        }

        // date
        //
        template <typename C>
        void date_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void date_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        date<C> date_pimpl<C>::
        post_date ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          int year (0);
          unsigned short month (0), day (0);
          std::basic_string<C> zone;

          // date := [-]CCYY[N]*-MM-DD[Z|(+|-)HH::MM]
          //

          if (size >= 10)
          {
            // Find the end of the year token.
            //
            size_type pos (tmp.find (C ('-'), 4));

            if (pos != ro_string<C>::npos && (size - pos - 1) >= 5)
            {
              ro_string<C> year_fragment (tmp.data (), pos);
              zc_istream<C> yis (year_fragment);
              yis >> year;

              ro_string<C> month_fragment (tmp.data () + pos + 1, 2);
              zc_istream<C> mis (month_fragment);
              mis >> month;

              ro_string<C> day_fragment (tmp.data () + pos + 4, 2);
              zc_istream<C> dis (day_fragment);
              dis >> day;

              pos += 6;

              if (pos < size)
                zone.assign (tmp.data () + pos, size - pos);
            }
          }

          return zone.empty ()
            ? date<C> (year, month, day)
            : date<C> (year, month, day, zone);
        }

        // time
        //
        template <typename C>
        void time_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void time_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        time<C> time_pimpl<C>::
        post_time ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          unsigned short hours (0), minutes (0);
          double seconds (0.0);
          std::basic_string<C> zone;

          // time := HH:MM:SS[.S+][Z|(+|-)HH::MM]
          //

          if (size >= 8)
          {
            ro_string<C> hour_fragment (tmp.data (), 2);
            zc_istream<C> his (hour_fragment);
            his >> hours;

            ro_string<C> minutes_fragment (tmp.data () + 3, 2);
            zc_istream<C> mis (minutes_fragment);
            mis >> minutes;

            // Find the end of the seconds fragment.
            //
            size_type pos (8);
            for (; pos < size; ++pos)
            {
              C c (tmp[pos]);

              if (c == C ('Z') || c == C ('+') || c == C ('-'))
                break;
            }

            ro_string<C> seconds_fragment (tmp.data () + 6, pos - 6);
            zc_istream<C> sis (seconds_fragment);
            sis >> seconds;

            if (pos < size)
              zone.assign (tmp.data () + pos, size - pos);
          }

          return zone.empty ()
            ? time<C> (hours, minutes, seconds)
            : time<C> (hours, minutes, seconds, zone);
        }


        // date_time
        //
        template <typename C>
        void date_time_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void date_time_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        template <typename C>
        date_time<C> date_time_pimpl<C>::
        post_date_time ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          int year (0);
          unsigned short month (0), day (0), hours (0), minutes (0);
          double seconds (0.0);
          std::basic_string<C> zone;

          // date_time := [-]CCYY[N]*-MM-DDTHH:MM:SS[.S+][Z|(+|-)HH::MM]
          //

          if (size >= 19)
          {
            // Find the end of the year token.
            //
            size_type pos (tmp.find (C ('-'), 4));

            if (pos != ro_string<C>::npos && (size - pos - 1) >= 14)
            {
              ro_string<C> year_fragment (tmp.data (), pos);
              zc_istream<C> yis (year_fragment);
              yis >> year;

              ro_string<C> month_fragment (tmp.data () + pos + 1, 2);
              zc_istream<C> mis (month_fragment);
              mis >> month;

              ro_string<C> day_fragment (tmp.data () + pos + 4, 2);
              zc_istream<C> dis (day_fragment);
              dis >> day;

              pos += 7; // Point to the first H.

              ro_string<C> hour_fragment (tmp.data () + pos, 2);
              zc_istream<C> his (hour_fragment);
              his >> hours;

              ro_string<C> minutes_fragment (tmp.data () + pos + 3, 2);
              zc_istream<C> min_is (minutes_fragment);
              min_is >> minutes;

              // Find the end of the seconds fragment.
              //
              pos += 6; // Point to the first S.

              size_type sec_end (pos + 2);
              for (; sec_end < size; ++sec_end)
              {
                C c (tmp[sec_end]);

                if (c == C ('Z') || c == C ('+') || c == C ('-'))
                  break;
              }

              ro_string<C> seconds_fragment (tmp.data () + pos, sec_end - pos);
              zc_istream<C> sis (seconds_fragment);
              sis >> seconds;

              if (sec_end < size)
                zone.assign (tmp.data () + sec_end, size - sec_end);
            }
          }

          return zone.empty ()
            ? date_time<C> (year, month, day, hours, minutes, seconds)
            : date_time<C> (year, month, day, hours, minutes, seconds, zone);
        }

        // duration
        //
        template <typename C>
        void duration_pimpl<C>::
        _pre ()
        {
          str_.clear ();
        }

        template <typename C>
        void duration_pimpl<C>::
        _characters (const ro_string<C>& s)
        {
          if (str_.size () == 0)
          {
            ro_string<C> tmp (s.data (), s.size ());

            if (trim_left (tmp) != 0)
              str_ += tmp;
          }
          else
            str_ += s;
        }

        namespace bits
        {
          template <typename C>
          inline typename ro_string<C>::size_type
          find_delim (const C* s,
                      typename ro_string<C>::size_type pos,
                      typename ro_string<C>::size_type size)
          {
            const C* p (s + pos);
            for (; p < (s + size); ++p)
            {
              if (*p == C ('Y') || *p == C ('D') || *p == C ('M') ||
                  *p == C ('H') || *p == C ('M') || *p == C ('S') ||
                  *p == C ('T'))
                break;
            }

            return p - s;
          }
        }

        template <typename C>
        duration duration_pimpl<C>::
        post_duration ()
        {
          typedef typename ro_string<C>::size_type size_type;

          ro_string<C> tmp (str_);
          size_type size (trim_right (tmp));

          bool negative (false);
          unsigned int years (0), months (0), days (0), hours (0), minutes (0);
          double seconds (0.0);

          // duration := [-]P[nY][nM][nD][TnHnMnS[.S+]]
          //
          const C* s (tmp.data ());

          if (size >= 3)
          {
            size_type pos (0);

            if (s[0] == C ('-'))
            {
              negative = true;
              pos++;
            }

            pos++; // Skip 'P'.

            size_type del (bits::find_delim (s, pos, size));

            if (del != size && s[del] == C ('Y'))
            {
              ro_string<C> fragment (s + pos, del - pos);
              zc_istream<C> is (fragment);
              is >> years;

              pos = del + 1;
              del = bits::find_delim (s, pos, size);
            }

            if (del != size && s[del] == C ('M'))
            {
              ro_string<C> fragment (s + pos, del - pos);
              zc_istream<C> is (fragment);
              is >> months;

              pos = del + 1;
              del = bits::find_delim (s, pos, size);
            }

            if (del != size && s[del] == C ('D'))
            {
              ro_string<C> fragment (s + pos, del - pos);
              zc_istream<C> is (fragment);
              is >> days;

              pos = del + 1;
              del = bits::find_delim (s, pos, size);
            }

            if (del != size && s[del] == C ('T'))
            {
              pos = del + 1;
              del = bits::find_delim (s, pos, size);

              if (del != size && s[del] == C ('H'))
              {
                ro_string<C> fragment (s + pos, del - pos);
                zc_istream<C> is (fragment);
                is >> hours;

                pos = del + 1;
                del = bits::find_delim (s, pos, size);
              }

              if (del != size && s[del] == C ('M'))
              {
                ro_string<C> fragment (s + pos, del - pos);
                zc_istream<C> is (fragment);
                is >> minutes;

                pos = del + 1;
                del = bits::find_delim (s, pos, size);
              }

              if (del != size && s[del] == C ('S'))
              {
                ro_string<C> fragment (s + pos, del - pos);
                zc_istream<C> is (fragment);
                is >> seconds;
              }
            }
          }

          return duration (
            negative, years, months, days, hours, minutes, seconds);
        }
      }
    }
  }
}

