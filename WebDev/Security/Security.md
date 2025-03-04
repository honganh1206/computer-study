# Security headers

- `Content-Security-Policy` (often abbreviated to CSP) headers are used to restrict where the resources for your web page (e.g. JavaScript, images, fonts etc) can be loaded from
- `Referrer-Policy` is used to **control what information is included in a `Referer` header** when a user navigates away from your web page.
- `X-Content-Type-Options: nosniff` instructs browsers to not MIME-type sniff the content- type of the response
- `X-Frame-Options: deny` is used to help prevent clickjacking attacks in older browsers that don’t support CSP headers.
- `X-XSS-Protection: 0` is used to disable the blocking of cross-site scripting attacks.


# HTTP & HTTPS

- HTTPS is essentially HTTP sent across a TLS (Transport Layer Security) connection => Data is encrypted and signed, which helps ensure its privacy and integrity during transit.
