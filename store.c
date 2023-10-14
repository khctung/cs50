{% capture email_title %}Your order is ready for pickup{% endcapture %}
{% capture email_body %}Bring your confirmation email when you come to collect your order.{% endcapture %}
{% capture email_body2 %}Orders can be picked up for 10 days following this email. At 7 days after order is ready, you will be notified that you will have 3 remaining days to pick up your order. At the 10 day mark, the customer will be refunded for 75% of their purchase. The Harvard Shop will retain 25% of the order value for restocking costs.{% endcapture %}

<!DOCTYPE html>
<html lang="en">
  <head>
  <title>{{ email_title }}</title>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <meta name="viewport" content="width=device-width">
  <link rel="stylesheet" type="text/css" href="/assets/notifications/styles.css">
  <style>
    .button__cell { background: {{ shop.email_accent_color }}; }
    a, a:hover, a:active, a:visited { color: {{ shop.email_accent_color }}; }
  </style>
</head>

  <body>
    <table class="body">
      <tr>
        <td>
          <table class="header row">
  <tr>
    <td class="header__cell">
      <center>

        <table class="container">
          <tr>
            <td>

              <table class="row">
                <tr>
                  <td class="shop-name__cell">
                    {%- if shop.email_logo_url %}
                      <img src="{{shop.email_logo_url}}" alt="{{ shop.name }}" width="{{ shop.email_logo_width }}">
                    {%- else %}
                      <h1 class="shop-name__text">
                        <a href="{{shop.url}}">{{ shop.name }}</a>
                      </h1>
                    {%- endif %}
                  </td>

                    <td class="order-number__cell">
                      <span class="order-number__text">
                        Order {{ order_name }}
                      </span>
                    </td>
                </tr>
              </table>

            </td>
          </tr>
        </table>

      </center>
    </td>
  </tr>
</table>

          <table class="row content">
  <tr>
    <td class="content__cell">
      <center>
        <table class="container">
          <tr>
            <td>

            <h2>{{ email_title }}</h2>

            {% if pickup_instructions != blank %}
              <p>{{ pickup_instructions }}</p>
            {% else %}
              <p>{{ email_body }}</p>
              <p>{{ email_body2 }}</p>
            {% endif %}

            <table class="section--margin">
  <tr>
    <td>
      <h4>Pickup location</h4>
    </td>
  </tr>
  <tr>
    <td>
      <p>{{ location.name }}</p>
    </td>
  </tr>
  <tr>
    <td>
      <p>{{ location.address1 }}</p>
    </td>
  </tr>
  {% if location.address2 != blank %}
  <tr>
    <td>
      <p>{{ location.address2 }}</p>
    </td>
  </tr>
  {% endif %}
  <tr>
    <td>
      <p>{{ location.city | capitalize }} {{ location.province | capitalize }} {{ location.zip | upcase }}</p>
    </td>
  </tr>
  <tr>
    <td class="empty-line">&nbsp;</td>
  </tr>
  <tr>
    <td>
      <a href="http://www.google.com/maps/search/?api=1&query={{ location.name }} - {{ [location.address1, location.address2].compact.join(', ') }}, {{ location.city }}, {{ location.province }}, {{ location.zip }}" target="_blank">
        Open map&nbsp;
        <span class="small">&rarr;</span>
      </a>
    </td>
  </tr>
</table>


            {% if order_status_url %}
              <table class="row actions">
  <tr>
    <td class="empty-line">&nbsp;</td>
  </tr>
  <tr>
    <td class="actions__cell">
      <table class="button main-action-cell">
        <tr>
          <td class="button__cell"><a href="{{ order_status_url }}" class="button__text">View your order</a></td>
        </tr>
      </table>
      {% if shop.url %}
    <table class="link secondary-action-cell">
      <tr>
        <td class="link__cell">or <a href="{{ shop.url }}">Visit our store</a></td>
      </tr>
    </table>
{% endif %}

    </td>
  </tr>
</table>

            {% else %}
              {% if shop.url %}
    <table class="row actions">
      <tr>
        <td class="actions__cell">
          <table class="button main-action-cell">
            <tr>
              <td class="button__cell"><a href="{{ shop.url }}" class="button__text">Visit our store</a></td>
            </tr>
          </table>
        </td>
      </tr>
    </table>
{% endif %}

            {% endif %}

            </td>
          </tr>
        </table>
      </center>
    </td>
  </tr>
</table>

          <table class="row section">
  <tr>
    <td class="section__cell">
      <center>
        <table class="container">
          <tr>
            <td>
              <h3>Order summary</h3>
            </td>
          </tr>
        </table>
        <table class="container">
          <tr>
            <td>


<table class="row">
  {% for line in subtotal_line_items %}
  <tr class="order-list__item">
    <td class="order-list__item__cell">
      <table>
        <td>
          {% if line.image %}
            <img src="{{ line | img_url: 'compact_cropped' }}" align="left" width="60" height="60" class="order-list__product-image"/>
          {% endif %}
        </td>
        <td class="order-list__product-description-cell">
          {% if line.product.title %}
            {% assign line_title = line.product.title %}
          {% else %}
            {% assign line_title = line.title %}
          {% endif %}

          {% if line.quantity < line.quantity %}
            {% capture line_display %} {{ line.quantity }} of {{ line.quantity }} {% endcapture %}
          {% else %}
            {% assign line_display = line.quantity  %}
          {% endif %}

          <span class="order-list__item-title">{{ line_title }}&nbsp;&times;&nbsp;{{ line_display }}</span><br/>

          {% if line.variant.title != 'Default Title' %}
            <span class="order-list__item-variant">{{ line.variant.title }}</span><br/>
          {% endif %}

          {% if line.selling_plan_allocation %}
            <span class="order-list__item-variant">{{ line.selling_plan_allocation.selling_plan.name }}</span><br/>
          {% endif %}

          {% if line.refunded_quantity > 0 %}
            <span class="order-list__item-refunded">Refunded</span>
          {% endif %}

          {% if line.discount_allocations %}
            {% for discount_allocation in line.discount_allocations %}
              {% if discount_allocation.discount_application.target_selection != 'all' %}
                <span class="order-list__item-discount-allocation">
                  <img src="{{ 'notifications/discounttag.png' | shopify_asset_url }}" width="18" height="18" class="discount-tag-icon" />
                  <span>
                    {{ discount_allocation.discount_application.title | upcase }}
                    (-{{ discount_allocation.amount | money }})
                  </span>
                </span>
              {% endif %}
            {% endfor %}
          {% endif %}
        </td>
          <td class="order-list__price-cell">
            {% if line.original_line_price != line.final_line_price %}
              <del class="order-list__item-original-price">{{ line.original_line_price | money }}</del>
            {% endif %}
            <p class="order-list__item-price">
              {% if line.final_line_price > 0 %}
                {{ line.final_line_price | money }}
              {% else %}
                Free
              {% endif %}
            </p>
          </td>
      </table>
    </td>
  </tr>{% endfor %}
</table>

            <table class="row subtotal-lines">
  <tr>
    <td class="subtotal-spacer"></td>
    <td>
      <table class="row subtotal-table">
        {% for discount_application in discount_applications %}
          {% if discount_application.target_selection == 'all' %}
            {% capture discount_title %}
              {% if discount_application.title %}
                {{ discount_application.title | upcase }}
              {% else %}
                Discount
              {% endif %}
            {% endcapture %}

<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Discount</span>
        <span class="subtotal-line__discount">
          <img src="{{ 'notifications/discounttag.png' | shopify_asset_url }}" width="18" height="18" class="discount-tag-icon" />
          <span class="subtotal-line__discount-title">{{ discount_title }}</span>
        </span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>-{{ discount_application.total_allocated_amount | money }}</strong>
  </td>
</tr>

          {% endif %}
        {% endfor %}


<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Subtotal</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ subtotal_price | money }}</strong>
  </td>
</tr>

        {% if delivery_method == 'pick-up' %}

<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Pickup</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ shipping_price | money }}</strong>
  </td>
</tr>

        {% else %}

<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Shipping</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ shipping_price | money }}</strong>
  </td>
</tr>

        {% endif %}

        {% if total_duties %}

<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Duties</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ total_duties | money }}</strong>
  </td>
</tr>

        {% endif %}


<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Taxes</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ tax_price | money }}</strong>
  </td>
</tr>


        {% if total_tip and total_tip > 0 %}

<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Tip</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ total_tip | money }}</strong>
  </td>
</tr>

        {% endif %}
      </table>
      {% assign transaction_size = 0 %}
      {% assign transaction_amount = 0 %}
      {% for transaction in transactions %}
        {% if transaction.status == "success" %}
        {% unless transaction.kind == "authorization" or transaction.kind == "void" %}
          {% assign transaction_size = transaction_size | plus: 1 %}
          {% assign transaction_amount = transaction_amount | plus: transaction.amount %}
        {% endunless %}
        {% endif %}
      {% endfor %}
      <table class="row subtotal-table subtotal-table--total">
      {% if payment_terms %}
        {% assign due_at_date = payment_terms.next_payment.due_at | date: "%b %d, %Y" %}

<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Total paid today</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ transaction_amount | money_with_currency }}</strong>
  </td>
</tr>

        <div class="payment-terms">

<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Total due {{ due_at_date }}</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ payment_terms.next_payment.amount_due | money_with_currency }}</strong>
  </td>
</tr>

        </div>
      {% else %}

<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Total</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ total_price | money_with_currency }}</strong>
  </td>
</tr>

      {% endif %}
      </table>

      {% if total_discounts > 0 %}
        <p class="total-discount">
          You saved <span class="total-discount--amount">{{ total_discounts | money }}</span>
        </p>
      {% endif %}

      {% unless payment_terms %}
      {% if transaction_size > 1 or transaction_amount < total_price %}
        <table class="row subtotal-table">
          <tr><td colspan="2" class="subtotal-table__line"></td></tr>
          <tr><td colspan="2" class="subtotal-table__small-space"></td></tr>

          {% for transaction in transactions %}
            {% if transaction.status == "success" and transaction.kind == "capture" or transaction.kind == "sale" %}
              {% if transaction.payment_details.credit_card_company %}
                {% capture transaction_name %}{{ transaction.payment_details.credit_card_company }} (ending in {{ transaction.payment_details.credit_card_last_four_digits }}){% endcapture %}
              {% else %}
                {% capture transaction_name %}{{ transaction.gateway_display_name }}{% endcapture %}
              {% endif %}


<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>{{transaction_name}}</span>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>{{ transaction.amount | money }}</strong>
  </td>
</tr>

            {% endif %}
            {% if transaction.kind == 'refund' %}
              {% if transaction.payment_details.credit_card_company %}
                {% assign refund_method_title = transaction.payment_details.credit_card_company %}
              {% else %}
                {% assign refund_method_title = transaction.gateway %}
              {% endif %}


<tr class="subtotal-line">
  <td class="subtotal-line__title">
    <p>
      <span>Refund</span>
        <br>
        <small>{{ refund_method_title | capitalize }}</small>
    </p>
  </td>
  <td class="subtotal-line__value">
    <strong>- {{ transaction.amount | money }}</strong>
  </td>
</tr>

            {% endif %}
          {% endfor %}
        </table>
      {% endif %}
      {% endunless %}
    </td>
  </tr>
</table>


            </td>
          </tr>
        </table>
      </center>
    </td>
  </tr>
</table>

          <table class="row footer">
  <tr>
    <td class="footer__cell">
      <center>
        <table class="container">
          <tr>
            <td>

              <p class="disclaimer__subtext">If you have any questions, reply to this email or contact us at <a href="mailto:{{ shop.email }}">{{ shop.email }}</a></p>
            </td>
          </tr>
        </table>
      </center>
    </td>
  </tr>
</table>

<img src="{{ 'notifications/spacer.png' | shopify_asset_url }}" class="spacer" height="1" />

        </td>
      </tr>
    </table>
  </body>
</html>
